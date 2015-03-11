#include "stdafx.h"

#include "Game.h"
#include "CTilemap.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::init(screenW, screenH, title);	
	
	this->m_tilemap = new CTileMap();
	this->m_tilemap->load("./data/map.txt");


	return errCode;
}

void Game::update(float deltaTime)
{
	
}

void Game::render(Graphics* g)
{
	g->setClearColor(0x000044ff);
	g->cleanScreen();
	m_tilemap->drawMap(g);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	printf("Key: %c - State: %d\n", key, state);
}