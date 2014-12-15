#include "stdafx.h"

#include "Game.h"

Image* back_ground;
Image* brick;

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);	
	back_ground = new Image("D:\\black-brick-wall.jpg");
	brick = new Image("D:\\brick75x50.jpg");
	
	brick->loadImage();
	back_ground->loadImage();
	return errCode;
}

void Game::Update(float deltaTime)
{
	
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->drawImage(back_ground, 0, 0);
	int k = 25;
	int brick_in_line = 9;
	for (int i = 1; i <= 3; i++)
	{
		int count = brick_in_line;
		int j = (i * 100)/2;
		while (count > 0)
		{
			g->drawImage(brick, j, k);
			j += 100;
			count--;
		}
		count = --brick_in_line;
		k += 85;
	}
}

void Game::Exit()
{
	
}