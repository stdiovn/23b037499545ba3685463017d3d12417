#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "Game.h"
#include "Brick.h"
#include "BrickType1.h"
#include "BrickType2.h"

#define SRCWidth 800
#define SRCHeight 600

#define GameOverImg "GameOver.jpg"
#define BackGround "Background.jpg"
Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);
	//Color
	m_SqrColor = 0x00FF00FF;
	//Rect
	R = new Rect;
	R->InitRect();
	//Square
	S = new Square;
	S->InitSquare();
	//Image
	GameOverImage = new Image(GameOverImg);
	ErrorCode code = GameOverImage->loadImage();
	Background = new Image(BackGround);
	Background->loadImage();
	//Map
	m_Map = 3;
	//Count alive
	m_CountAlive = 0;
	//File
	f = fopen("Map.tat", "rb");
	char* buf = new char[Row * Column];
	fseek(f, (Row* Column + 2) * (m_Map-1) , SEEK_SET);
	fread(buf, 1, Row* Column, f);
	fclose(f);
	//Brick
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			B[i][j] = NULL;
			int Number = int(buf[Column * i + j]) - 48;
			int Type = (BrickType)Number;
			if (Type == 1)
			{
				B[i][j] = new Type1;
			}
			else
			{
				B[i][j] = new Type2;
			}
			B[i][j]->SetCounti(i);
			B[i][j]->SetCountj(j);
			B[i][j]->InitBrick();
		}
	}
	delete buf;
	buf = NULL;
	return errCode;
}

void Game::LimitFPS(int LimitFPS, float DeltaTime)
{
	int LimitFDT;
	LimitFDT = 1000 / LimitFPS;
	if ( DeltaTime < LimitFDT)
	{
		Sleep(LimitFDT - DeltaTime);
	}
}

unsigned int Game::ColorRandom(int Red, int Green, int Blue, int Alpha)
{
	return ((Red << 24) | (Green << 16) | (Blue << 8) | Alpha);
}

void Game::Update(float deltaTime)
{
	//Limit FPS
	LimitFPS(60, deltaTime);
	//transfer square
	S->TransferSquare(R);
	m_CountAlive = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (B[i][j]->GetLive() != 0)
			{
				S->ConllideSquare(R, B[i][j]);
			}
			else
			{
				m_CountAlive++;
			}
		}
	}

	//Press Key
	if (!S->GetIsConllideRect())
	{
		R->TransferRect(getKeyState(KEY_RIGHT), getKeyState(KEY_LEFT));
	}
	//Change Map
	if (m_CountAlive == Row * Column)
	{
		m_Map++;
	}
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	static bool GameOver = false;
	static int Counting = 0;
	if (!GameOver)
	{
		//Draw background
		g->drawImage(Background,0,0);
		//Draw brick
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				B[i][j]->SetCounti(i);
				B[i][j]->SetCountj(j);
				if (B[i][j]->GetLive() != 0)
				{
					g->drawImage(B[i][j]->GetImage(), B[i][j]->GetBrickX(), B[i][j]->GetBrickY());
				}
			}
		}

		//Draw square
		g->drawImage(S->GetSquareImage(), S->GetSqrX(), S->GetSqrY());
		//Draw rect
		g->drawImage(R->GetRectImage(), R->GetRectX(), R->GetRectY());

		if (S->GetSqrY() + SqrWidth >= SRCHeight)
		{
			GameOver = true;
		}
	}
	else
	{
		g->drawImage(GameOverImage, 0, 0);
		Counting++;
		if (Counting == 120)
		{
			GameOver = false;
			Counting = 0;
		}
	}
}

void Game::Exit()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			B[i][j]->ReleaseBrick();
		}
	}
	S->ReleaseSquare();
	R->ReleaseRect();
}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////

void main()
{
	Game g;
	
	g.Init(SRCWidth, SRCHeight, "Game");
	g.Run();
	g.Exit();
}