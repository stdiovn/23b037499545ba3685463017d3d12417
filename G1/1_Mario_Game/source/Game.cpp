#include "stdafx.h"

#include "Mushroom.h"

#include "Map.h"
#include "ResourcesManager.h"

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

	//Coder: Tai

	m_map = new Map("map//Stage1-1.txt");
	m_map->loadMap();

	/////////////////////////////////////////////////
	//Coder: Rye
	m_state = GameState::STATE_PLAY;

	m_mario = new Mario(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_MARIO), 
						ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_MARIO));
	/////////////////////////////////////////////////


	return errCode;
}

void Game::update(float deltaTime)
{
	/////////////////////////////////////////////////
	//Coder: Rye
	m_mario->update();
	/////////////////////////////////////////////////
	


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

	m_map->drawMap(g);
	m_mario->draw(g);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}