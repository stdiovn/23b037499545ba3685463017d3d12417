#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "Game.h"
#include <stdlib.h>
#include <ctime>
#include "Sprite.h"
#include "STDIO_FW\Video\Image.h"
#define FPS 30
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define RED 0xFF0000FF
#define YELLOW 0xFFFF00FF
#define PURPLE 0x7030A0FF

#define Height_imageWall 50
#define Width_imageWall 50
#define WallPerRow 16


int Count = 48;
Rect *FrameWall = new Rect[Count];

Rect ball(100, 130, 200, 230, std::pair<int, int>(2, 2));
Rect RectMove(50, 250, 570, 600, std::pair<int, int>(4, 4));

int color = RED;

Image *img = new Image("pink.png");
Image *imgWall = new Image("wall.png");

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
		return (X + x.X, Y + x.Y);
	}
};

Vector2D veclocity(2,2);

Game::Game()
{

}

Game::~Game()
{

}

void SetPositionForWall(Rect *FrameWall, int CountWall)
{
	for (int i = 0; i < CountWall; i++)
	{
		int width = Width_imageWall;
		int height = Height_imageWall;

		FrameWall[i].m_Left = (i % WallPerRow) * width;
		FrameWall[i].m_Right = FrameWall[i].m_Left + width;
		FrameWall[i].m_Top = (i / WallPerRow) * height;
		FrameWall[i].m_Bottom = FrameWall[i].m_Top + height;
	}
}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	img->loadImage();
	img->scale(0.25);


	imgWall->loadImage();
	float scale = imgWall->getWidth();
	imgWall->scale((float)Width_imageWall / scale);
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

	
	if (getKeyState(KeyCode::KEY_LEFT))
		RectMove.KeyBoard(KeyCode::KEY_LEFT);
	else if (getKeyState(KeyCode::KEY_RIGHT))
		RectMove.KeyBoard(KeyCode::KEY_RIGHT);
	
	ball.Update();

	for (int i = 0; i < Count; i++)
	{
		if (FrameWall[i].IsDraw && ball.IsPact(FrameWall[i]))
		{
			FrameWall[i].IsDraw = false;
			color = rand() % 3 + 1;
		}
	}

	ball.IsPact(RectMove);

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

	for (int i = 0; i < Count; i++)
	{
		if (FrameWall[i].IsDraw == true)
		{
			g->drawImage(imgWall,FrameWall[i].m_Left, FrameWall[i].m_Top);
		}
	}

	g->drawRect(RectMove.m_Left, RectMove.m_Top, RectMove.m_Right - RectMove.m_Left, RectMove.m_Bottom - RectMove.m_Top);

	g->drawImage(img, ball.m_Left, ball.m_Top);
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
	SetPositionForWall(FrameWall, Count);	
	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");
	g.Run();
}