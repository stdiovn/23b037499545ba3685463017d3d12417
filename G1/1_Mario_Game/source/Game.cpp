#include "stdafx.h"

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
	m_map->initMap();


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
	
	std::vector<InformationObject> listObjects = m_map->getInformationObjectsOnCamera();
	std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin();
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
			}
		}
		curInformationObjects++;
	}


	////Coder: Tai

	std::vector<LuckyBox*>	listItems = m_map->getItemsOnCamera();

	std::vector<Enemy*>	listEnemy = m_map->getEnemysOnCamera();
	m_map->update();

	for (std::vector<Enemy*>::iterator temp = listEnemy.begin(); temp != listEnemy.end(); temp++)
	{
		Vec2 position = (*temp)->getPosition();
		Rect bound = (*temp)->getRect();
		for (std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin(); curInformationObjects != listObjects.end(); curInformationObjects++)
		{
			if (curInformationObjects->m_id == ID_PIPE_ON_MAP || curInformationObjects->m_id == ID_STAIR_ON_MAP 
				|| curInformationObjects->m_id == ID_STAND_ON_MAP)
			{
				Direction direct = g_isCollide(Rect(position.x, position.y, bound.width, bound.height), curInformationObjects->m_rect, (*temp)->getVeloc());

				if (direct == Direction::DIR_TOP || direct == Direction::DIR_TOP_LEFT || direct == Direction::DIR_TOP_RIGHT)
				{
					Vec2 position = (*temp)->getPosition();

					position.y = curInformationObjects->m_rect.y - (*temp)->getRect().height;
					(*temp)->setPosition(position.x, position.y);
				}
				else if (direct == Direction::DIR_LEFT)
				{
					Vec2 position = (*temp)->getPosition();

					position.x = curInformationObjects->m_rect.x - bound.width;
					(*temp)->setPosition(position.x, position.y);

					Vec2 veclocity = (*temp)->getVeloc();
					veclocity.x *= -1;
					(*temp)->setVeloc(veclocity.x, veclocity.y);
				}
				else if (direct == Direction::DIR_RIGHT)
				{
					Vec2 position = (*temp)->getPosition();

					position.x = curInformationObjects->m_rect.x + curInformationObjects->m_rect.width;
					(*temp)->setPosition(position.x, position.y);

					Vec2 veclocity = (*temp)->getVeloc();
					veclocity.x *= -1;
					(*temp)->setVeloc(veclocity.x, veclocity.y);
				}
			}
		}

		for (int i = 0; i < listItems.size(); i++)
		{
			Vec2 item = listItems[i]->getBox()->getPosition();
			Rect itembound = listItems[i]->getBox()->getRect();

			Direction direc = g_isCollide(Rect(position.x, position.y, bound.width, bound.height), Rect(item.x, item.y, itembound.width, itembound.height), (*temp)->getVeloc());
			if (direc == Direction::DIR_TOP || direc == Direction::DIR_TOP_LEFT || direc == Direction::DIR_TOP_RIGHT)
			{
				position.y = item.y - bound.height;

				(*temp)->setPosition(position.x, position.y);
			}
		}
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