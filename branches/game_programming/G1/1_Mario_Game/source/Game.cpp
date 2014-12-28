#include "stdafx.h"

#include "Mario.h"

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
	
	/////////////////////////////////////////////////
	//Coder: Rye
	//Purpose: Set Font for render text
	Font::initFontLib();

	m_font = new Font("font//Montserrat-Regular.ttf");
	m_font->loadFont();
	getGraphics()->setFont(m_font);
	/////////////////////////////////////////////////

	

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

	g->drawText("Test", 100, 100);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}