#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"

#include "Game.h"

#include <time.h>
#include <Windows.h>

#define SRCWidth 800
#define SRCHeight 600

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);
	m_SqrColor = 0x00FF00FF;
	R = new Rect;
	R->InitRect();
	S = new Square;
	S->InitSquare();
	GameOverImage = new Image("GameOver.jpg");
	ErrorCode code = GameOverImage->loadImage();
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
	//Press Key
	R->TransferRect(getKeyState(KEY_RIGHT), getKeyState(KEY_LEFT));
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	//Draw square
	g->drawImage(S->GetSquareImage(), S->GetSqrX(), S->GetSqrY());
	//Draw rect
	g->drawImage(R->GetRectImage(), R->GetRectX(), R->GetRectY());
	//Draw Game Over Image 
	if (S->GetSqrY() + SqrWidth >= SRCHeight)
	{
		int StarTime = clock();
		g->cleanScreen();
		GameOverImage->scale(3);
		g->drawImage(GameOverImage, 0, 0);
		int EndTime = clock();
		if ((EndTime - StarTime) > 1000 / 5)
		{
			Sleep(1000 / 5 - (EndTime - StarTime));
		}
	}
}

void Game::Exit()
{
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
}