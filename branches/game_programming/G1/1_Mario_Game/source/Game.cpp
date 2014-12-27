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
	Font::initFontLib();

	m_font = new Font("font//BodoniFLF-Bold.ttf");
	m_font->loadFont();
	getGraphics()->setFont(m_font);

	return errCode;
}

void Game::update(float deltaTime)
{


	/////////////////////////////////////////////////
	//Coder: Rye
	//Purpose: manage FPS
	if(1000.0f / FPS > deltaTime)
		Sleep(1000.0f / FPS - deltaTime);
}

void Game::render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0xFFFFFFFF);
	g->drawText("Test", 0, 0);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}