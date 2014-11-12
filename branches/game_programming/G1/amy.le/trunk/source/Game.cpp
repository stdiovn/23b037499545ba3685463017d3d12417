#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "Game.h"

#define SrcWidth 800
#define SrcHeight 600
#define MapWidth 100
#define MapHeight 16
#define TiledWidth 12
#define TiledHeight 17
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
	//File
	f = fopen("Map.txt", "rb");
	fseek(f, 0, SEEK_END);
	int m_size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buf = new char[m_size];
	fread(buf, 1, m_size, f);
	fclose(f);

	m_Map = new int*[MapHeight];
	for (int i = 0; i < MapHeight; i++)
	{
		m_Map[i] = new int[MapWidth];
	}

	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			m_Map[i][j] = 0;
			while (*buf != ',')
			{
				m_Map[i][j] *= 10;
				m_Map[i][j] += *buf - 48;
				buf++;
			}
			buf++;
		}
		buf += 2;
	}

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

void Game::Update(float deltaTime)
{
	//Limit FPS
	LimitFPS(60, deltaTime);
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	for (int i = 0; i < MapWidth; i++)
	{
		for (int j = 0; j < MapHeight; j++)
		{
		
		}
	}
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