#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "Game.h"

#define SrcWidth 800
#define SrcHeight 600

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
	//Turtle
	Tur = new Turtle;
	Tur->Init();
	//Boomerang
	Bmr = new Boomerang;
	Bmr->Init();
	//Image
	m_GameOverImage = new Image(GameOverImg);
	ErrorCode code = m_GameOverImage->loadImage();
	m_Background = new Image(BackGround);
	m_Background->loadImage();
	//Map
	m_Map = 1;
	//Count alive
	m_CountIsAlive = 0;
	//File
	f = fopen("Map.tat", "rb");
	char* buf = new char[Row * Column];
	fseek(f, (Row* Column + 2) * (m_Map - 1), SEEK_SET);
	fread(buf, 1, Row* Column, f);
	fclose(f);
	//Brick
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			Brk[i][j] = new Brick;
			Brk[i][j]->SetCounti(i);
			Brk[i][j]->SetCountj(j);
			Brk[i][j]->Init();
			int Number = int(buf[Column * i + j]) - 48;
			Brk[i][j]->SetIsAlive(Number);
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
	//Turtle
	Tur->GetRect()->TransferOfControlledRect(getKeyState(KEY_LEFT), getKeyState(KEY_RIGHT));
	//Boomerang
	Bmr->Tranfer();
	Bmr->Collide(Tur->GetRect());
	//Brick
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			Bmr->Collide(Brk[i][j]->GetRect());
			if (Bmr->GetRect()->GetIsCollide())
			{
				Brk[i][j]->SetIsAlive(Brk[i][j]->GetIsAlive() - 1);
			}
			if (Brk[i][j]->GetIsAlive() < 0)
			{
				m_CountIsAlive++;
			}
		}
	}
	//Change map
	if (m_CountIsAlive == Row*Column)
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
		g->drawImage(m_Background, 0, 0);
		//Draw Boomerang
		g->drawImage(Bmr->GetImage(), Bmr->GetRect()->GetX(), Bmr->GetRect()->GetY());

		//Draw brick
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				Brk[i][j]->SetCounti(i);
				Brk[i][j]->SetCountj(j);
				if (Brk[i][j]->GetIsAlive() != 0)
				{
					g->drawImage(Brk[i][j]->GetImage(), Brk[i][j]->GetRect()->GetX(), Brk[i][j]->GetRect()->GetY());
				}
			}
		}

		//Draw turtle
		g->drawImage(Tur->GetImage(), Tur->GetRect()->GetX(), Tur->GetRect()->GetY());
		

		if (Bmr->GetRect()->GetY() + SrcWidth >= SrcHeight)
		{
			GameOver = true;
		}
	}
	//else
	//{
	//	g->drawImage(m_GameOverImage, 0, 0);
	//	Counting++;
	//	if (Counting == 120)
	//	{
			GameOver = false;
	//		Counting = 0;
	//	}
	//}
}

void Game::Exit()
{

}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////

void main()
{
	Game g;
	
	g.Init(SrcWidth, SrcHeight, "Game");
	g.Run();
	g.Exit();
}