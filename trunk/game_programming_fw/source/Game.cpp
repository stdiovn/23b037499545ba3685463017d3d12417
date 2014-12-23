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

	return errCode;
}

void Game::update(float deltaTime)
{
	
}

void Game::render(Graphics* g)
{
	g->cleanScreen();
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	printf("Key: %c - State: %d\n", key, state);
}