#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "Game.h"
#include <stdlib.h>
#include <ctime>


#define FPS 30
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define RED 0xFF0000FF
#define YELLOW 0xFFFF00FF
#define PURPLE 0x7030A0FF


struct Vector2D
{
	int X;
	int Y;

	Vector2D(int X = 0, int Y = 0)
	{
		this->X = X;
		this->Y = Y;
	}

	Vector2D operator +(Vector2D x)
	{
		return Vector2D(X + x.X, Y + x.Y);
	}
};

Vector2D positionRect(100, 100), veclocity(1, 1);
Vector2D positionRect2(50, 550), veclocity2(2,0);
int color = RED;


Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	return errCode;
}

void Game::Update(float deltaTime)
{
	float CurrenTime;
	float StartTime = GetTickCount();
	do
	{
		CurrenTime = GetTickCount();
		CurrenTime = CurrenTime - StartTime + deltaTime;
	} while (CurrenTime < (float)1000 / FPS);
	

	// hinh vuong
	positionRect = positionRect + veclocity;

	if (positionRect.X + 100 > SCREEN_WIDTH || positionRect.X < 0)
	{
		veclocity.X = -veclocity.X;
		color = rand() % 3 + 1;
	}
	else 
	if (positionRect.Y + 100 > SCREEN_HEIGHT || positionRect.Y < 0)
	{
		veclocity.Y = -veclocity.Y;
		color = rand() % 3 + 1;
	}

	// hinh chu nhat
	positionRect2.X += veclocity2.X;

	if (positionRect2.X + 200 > SCREEN_WIDTH || positionRect2.X < 0) 
		veclocity2.X = -veclocity2.X;


	switch (color)
	{
	case 1:
		color = RED;
		break;
	case 2:
		color = PURPLE;
		break;
	case 3:
		color = YELLOW;
		break;
	}
}


void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(color);

	g->drawRect(positionRect.X, positionRect.Y, 100, 100);
	g->fillRect(positionRect.X, positionRect.Y, 100, 100);

	g->drawRect(positionRect2.X, positionRect2.Y, 200, 50);
}


void Game::Exit()
{

}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	srand(time(NULL));
	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");


	g.Run();
}