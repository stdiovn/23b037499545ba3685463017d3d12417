#include "stdafx.h"
#include "Game.h"

Brick br;


Game::Game()
{

}
Game::~Game()
{
	
}

ErrorCode Game::init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::init(screenW, screenH, title);	
	ball.Init();
	bar.Init();
	inputArr(ArrBrick);
	for (int i = 0; i < ArrBrick.size(); i++)ArrBrick[i].Init();

	return errCode;
}

void Game::update(float deltaTime)
{
	if (getKeyState(KEY_LEFT))
	{
		bar.moveleft();
		if (Collision(ball.getRect(), bar.getRect()) || Collision(bar.getRect(), ball.getRect()))ball.setDirection(WN);
	}
	if (getKeyState(KEY_RIGHT))
	{
		bar.moveright();
		if (Collision(ball.getRect(), bar.getRect()) || Collision(bar.getRect(), ball.getRect()))ball.setDirection(EN);
	}
	if (Collision(ball.getRect(), bar.getRect()) || Collision(bar.getRect(), ball.getRect()))ball.setDirection(ball.getDirection());
	for each(Brick brick in ArrBrick)
	{
		if (Collision(ball.getRect(), brick.getRect()) && br.getalive())
		{
	
			ball.setalive(ball.getDirection());
			brick.setalive(false);
		}
	}
	
	ball.Update();
}

void Game::render(Graphics* g)
{
	g->cleanScreen();	
	ball.Render(g);
	bar.Render(g);
	
	for each(Brick b in ArrBrick)b.Render(g);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{

}