#include "stdafx.h"
#include "Game.h"



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
	for (int i = 0; i < ArrBrick.size(); i++)
	{
		if (Collision(ball.getRect(), ArrBrick[i].getRect()) && ArrBrick[i].getalive()== true)
		{
	
			ball.setalive(ball.getDirection());
			ArrBrick[i].setalive(false);
			
		}
	}
	ball.Update();
}

void Game::render(Graphics* g)
{
	g->cleanScreen();	
	ball.Render(g);
	bar.Render(g);
	for (int i = 0; i < ArrBrick.size(); i++)ArrBrick[i].Render(g);
}

void Game::exit()
{
	ArrBrick.clear();
}

void Game::onKeyProc(KeyCode key, KeyState state)
{

}