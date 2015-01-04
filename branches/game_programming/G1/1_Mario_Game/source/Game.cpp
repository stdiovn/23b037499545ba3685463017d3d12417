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
	/*Font::initFontLib();

	m_font = new Font("font//Montserrat-Regular.ttf");
	m_font->loadFont();
	getGraphics()->setFont(m_font);*/
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
	

	std::list<InformationObject> listObjects = m_map->getInformationObjects();
	std::list<InformationObject>::iterator curInformationObjects = listObjects.begin();
	while(curInformationObjects != listObjects.end())
	{
		InformationObject x = *curInformationObjects;
		if(x.m_id == 1)
		{
			Rect marioBound = m_mario->getRect();
			Vec2 marioPosition = m_mario->getWorldPosition();
			Direction dir = g_isCollide(Rect(marioPosition.x, marioPosition.y, marioBound.width, marioBound.height), x.m_rect, m_mario->getVeloc());
			if(dir == Direction::DIR_TOP)
			{
				m_mario->setGroundPosition(x.m_rect.y);
				break;
			}
		}

		curInformationObjects++;
	}

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
	g->setClearColor(0x5C94FCFF);
	g->setColor(0xFFFFFFFF);

	Vec2 camera = m_mario->getWorldPosition();
	if(camera.x >= SCREEN_WIDTH / 2)
		m_map->setCamera(-(camera.x - SCREEN_WIDTH / 2), 0);

	m_map->drawMap(g);
	m_mario->draw(g);
}

void Game::exit()
{
	m_map->unloadMap();
	SAFE_DEL(m_map);

	SAFE_DEL(m_mario);

	ResourcesManager::getInstance()->unloadResources();
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}