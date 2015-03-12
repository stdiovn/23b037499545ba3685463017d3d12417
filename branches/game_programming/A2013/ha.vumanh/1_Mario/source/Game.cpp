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
	
	//Game Maps
	map = new Maps("tileset.png");
	map->openMapTiles("map.txt");
	map->modifiedSth(screenW,screenH);

	return errCode;
}

void Game::update(float deltaTime)
{

}

void Game::render(Graphics* g)
{
	g->setClearColor(0x6698FF00);
	g->cleanScreen();
	map->render(g);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	printf("Key: %c - State: %d\n", key, state);

	if (key == KeyCode::KEY_D)
	{
		map->goRight();
	}
	if (key == KeyCode::KEY_A)
	{
		map->goLeft();
	}
}