#include "stdafx.h"

#include "Map.h"
#include "ResourcesManager.h"
#include "MarioOwnedState.h"
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
	m_map->update();
	m_mario->updateVelocity();

	std::vector<InformationObject> listObjects = m_map->getInformationObjectsOnCamera();
	std::vector<Bullet*> listBulletShooted = m_mario->getGun()->getBulletShooted();
	std::vector<LuckyBox*>	listItems = m_map->getItemsOnCamera();
	std::vector<Enemy*>	listEnemy = m_map->getEnemysOnCamera();

	//Coder: Tai
	//------------------------------------------------------Mario Collision
	//where mario can stand, dont move on map
#pragma region Mario
	Rect marioBound = m_mario->getRect();
	Vec2 marioPosition = m_mario->getWorldPosition();

	for (std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin(); curInformationObjects != listObjects.end(); curInformationObjects++)
	{
		InformationObject x = *curInformationObjects;
		Direction dir;

		dir = g_isCollide(Rect(marioPosition.x, marioPosition.y, marioBound.width, marioBound.height), x.m_rect, m_mario->getVeloc());
		if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
		{
			m_mario->setVeloc(m_mario->getVeloc().x, 0);
			m_mario->setLocation(Location::LOC_ON_GROUND);
			marioPosition.y = x.m_rect.y - marioBound.height;
			m_mario->setGroundPosition(x.m_rect.y);
		}
		else if (dir == Direction::DIR_LEFT)
		{
			marioPosition.x = x.m_rect.x - marioBound.width;
			m_mario->setVeloc(0, m_mario->getVeloc().y);
			m_mario->setLocation(Location::LOC_ON_GROUND);
		}
		else if (dir == Direction::DIR_RIGHT)
		{
			marioPosition.x = x.m_rect.x + x.m_rect.width;
			m_mario->setVeloc(0, m_mario->getVeloc().y);
			m_mario->setLocation(Location::LOC_ON_GROUND);
		}

		m_mario->setWorldPosition(marioPosition.x, marioPosition.y);
	}

	// collision with item
	for (std::vector<LuckyBox*>::iterator temp = listItems.begin(); temp != listItems.end(); temp++)
	{
		if (!(*temp)->getActive()) continue;

		//update when mushroom bigger in luckybox, if mario is big, mushroom bigger will be change gun
		if ((*temp)->getType() == ItemsType::IT_MUSHROOM_BIGGER && m_mario->isBig())
		{
			(*temp)->changeItemsType(ItemsType::IT_GUN);
		}

		Vec2 itemPosition = (*temp)->getBox()->getPosition();
		Rect itemBound = (*temp)->getBox()->getRect();

		Direction dir = g_isCollide(Rect(marioPosition.x, marioPosition.y, marioBound.width, marioBound.height), Rect(itemPosition.x, itemPosition.y, itemBound.width, itemBound.height), m_mario->getVeloc());
		if (dir == Direction::DIR_BOTTOM || dir == Direction::DIR_BOTTOM_LEFT || dir == Direction::DIR_BOTTOM_RIGHT)
		{
			(*temp)->setCollision(true);

			marioPosition.y = itemPosition.y + itemBound.height;
			m_mario->setWorldPosition(marioPosition.x, marioPosition.y);
			m_mario->setGroundPosition(itemPosition.y);
			m_mario->getStateMachine()->changeState(Falling::getInstance());
		}
		else if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
		{
			marioPosition.y = itemPosition.y - marioBound.height;
			m_mario->setVeloc(m_mario->getVeloc().x, 0);
			m_mario->setLocation(Location::LOC_ON_GROUND);
			m_mario->setGroundPosition(itemPosition.y);
		}
		else if (dir == Direction::DIR_LEFT)
		{
			marioPosition.x = itemPosition.x - marioBound.width;
			m_mario->setVeloc(0, m_mario->getVeloc().y);
			m_mario->setLocation(Location::LOC_ON_GROUND);
		}
		else if (dir == Direction::DIR_RIGHT)
		{
			marioPosition.x = itemPosition.x + itemBound.width;
			m_mario->setVeloc(0, m_mario->getVeloc().y);
			m_mario->setLocation(Location::LOC_ON_GROUND);
		}

		m_mario->setWorldPosition(marioPosition.x, marioPosition.y);
	}
#pragma endregion
	


	//--------------------------------------------------------------Enemy Collision
	//where enemy can stand, dont move om map. When enemy be dead
#pragma region Enemy
	for (std::vector<Enemy*>::iterator temp = listEnemy.begin(); temp != listEnemy.end(); temp++)
	{
		if ((*temp)->getAttack()) continue;

		Vec2 position = (*temp)->getPosition();
		Rect bound = (*temp)->getRect();

		//enemy stand, can move on map
		for (std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin(); curInformationObjects != listObjects.end(); curInformationObjects++)
		{
			if (curInformationObjects->m_id == ID_PIPE_ON_MAP || curInformationObjects->m_id == ID_STAIR_ON_MAP
				|| curInformationObjects->m_id == ID_STAND_ON_MAP)
			{
				Direction direct = g_isCollide(Rect(position.x, position.y, bound.width, bound.height), curInformationObjects->m_rect, (*temp)->getVeloc());

				if (direct == Direction::DIR_TOP || direct == Direction::DIR_TOP_LEFT || direct == Direction::DIR_TOP_RIGHT)
				{
					Vec2 position = (*temp)->getPosition();

					position.y = curInformationObjects->m_rect.y - (*temp)->getRect().height - 1;
					(*temp)->setPosition(position.x, position.y);
				}
				else if (direct == Direction::DIR_LEFT)
				{
					Vec2 position = (*temp)->getPosition();

					position.x = curInformationObjects->m_rect.x - bound.width - 1;
					(*temp)->setPosition(position.x, position.y);

					Vec2 veclocity = (*temp)->getVeloc();
					veclocity.x *= -1;
					(*temp)->setVeloc(veclocity.x, veclocity.y);

					(*temp)->setFlipping(FLIP_NONE);
				}
				else if (direct == Direction::DIR_RIGHT)
				{
					Vec2 position = (*temp)->getPosition();

					position.x = curInformationObjects->m_rect.x + curInformationObjects->m_rect.width + 1;
					(*temp)->setPosition(position.x, position.y);

					Vec2 veclocity = (*temp)->getVeloc();
					veclocity.x *= -1;
					(*temp)->setVeloc(veclocity.x, veclocity.y);

					(*temp)->setFlipping(FLIP_X);
				}
			}
		}

		// enemy collision with items
		for (int i = 0; i < listItems.size(); i++)
		{
			Vec2 item = listItems[i]->getBox()->getPosition();
			Rect itembound = listItems[i]->getBox()->getRect();

			Direction direc = g_isCollide(Rect(position.x, position.y, bound.width, bound.height), Rect(item.x, item.y, itembound.width, itembound.height), (*temp)->getVeloc());
			if (direc == Direction::DIR_TOP || direc == Direction::DIR_TOP_LEFT || direc == Direction::DIR_TOP_RIGHT)
			{
				position.y = item.y - bound.height - 1;

				(*temp)->setPosition(position.x, position.y);
			}
		}

		// enemy collision with mario
		Vec2	marioPosition = m_mario->getWorldPosition();
		Rect	marioBound = m_mario->getRect();
		Direction dir = g_isCollide(Rect(marioPosition.x, marioPosition.y, marioBound.width, marioBound.height), Rect(position.x, position.y, bound.width, bound.height), m_mario->getVeloc());

		if ((*temp)->getTypeEnemy() != EnemysType::ET_FLOWER)
		{
			if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				(*temp)->setCollsion(true);
				marioPosition.y = (*temp)->getPosition().y - marioBound.height;
				m_mario->setWorldPosition(marioPosition.x, marioPosition.y);
				m_mario->getStateMachine()->changeState(Jumping::getInstance());
			}
		}
	}
#pragma endregion

	/////---------------------------------------Bullets Collision

#pragma region Bullet
	for (int i = 0; i < listBulletShooted.size(); i++)
	{
		Vec2 bulletPosition = listBulletShooted[i]->getPosition();
		Rect bulletBound = listBulletShooted[i]->getRect();
		Direction dir;

		// bullet collision with item
		for (std::vector<LuckyBox*>::iterator temp = listItems.begin(); temp != listItems.end(); temp++)
		{
			Vec2 itemPosition = (*temp)->getBox()->getPosition();
			Rect itemBound = (*temp)->getBox()->getRect();

			dir = g_isCollide(Rect(bulletPosition.x, bulletPosition.y, bulletBound.width, bulletBound.height), Rect(itemPosition.x, itemPosition.y, itemBound.width, itemBound.height), listBulletShooted[i]->getVeloc());
			if (dir == Direction::DIR_LEFT)
			{
				listBulletShooted[i]->setPosition(itemPosition.x - bulletBound.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
			}
			else if (dir == Direction::DIR_RIGHT)
			{
				listBulletShooted[i]->setPosition(itemPosition.x + itemBound.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
			}
			else if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				listBulletShooted[i]->setPosition(bulletPosition.x, itemPosition.y - bulletBound.height - 1);
				listBulletShooted[i]->setTime(0.0f);
			}
		}


		//bullet collision with stand position, pipe, stair on map
		for (std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin(); curInformationObjects != listObjects.end(); curInformationObjects++)
		{
			InformationObject x = *curInformationObjects;

			dir = g_isCollide(Rect(bulletPosition.x, bulletPosition.y, bulletBound.width, bulletBound.height), x.m_rect, listBulletShooted[i]->getVeloc());
			if (dir == Direction::DIR_LEFT)
			{
				listBulletShooted[i]->setPosition(x.m_rect.x - bulletBound.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
			}
			else if (dir == Direction::DIR_RIGHT)
			{
				listBulletShooted[i]->setPosition(x.m_rect.x + x.m_rect.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
			}
			else if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				listBulletShooted[i]->setPosition(bulletPosition.x, x.m_rect.y - bulletBound.height - 1);
				listBulletShooted[i]->setTime(0.0f);
			}
		}


		//bullets collision with enemy
		for (std::vector<Enemy*>::iterator temp = listEnemy.begin(); temp != listEnemy.end(); temp++)
		{
			Vec2 position = (*temp)->getPosition();
			Rect bound = (*temp)->getRect();


			dir = g_isCollide(Rect(bulletPosition.x, bulletPosition.y, bulletBound.width, bulletBound.height), Rect(position.x, position.y, bound.width, bound.height), listBulletShooted[i]->getVeloc());
			if (dir == Direction::DIR_LEFT)
			{
				listBulletShooted[i]->setPosition(position.x - bulletBound.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
				(*temp)->setAttack(true);
			}
			else if (dir == Direction::DIR_RIGHT)
			{
				listBulletShooted[i]->setPosition(position.x + bound.width, bulletPosition.y);
				listBulletShooted[i]->setCollsion(true);
				(*temp)->setAttack(true);
			}
			else if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				listBulletShooted[i]->setPosition(bulletPosition.x, position.y - bulletBound.height - 1);
				listBulletShooted[i]->setTime(0.0f);
				listBulletShooted[i]->setCollsion(true);
				(*temp)->setAttack(true);
			}
		}
	}
#pragma endregion	


	//-----------------------------------------------Item in LuckyBox Collision
	for (std::vector<LuckyBox*>::iterator temp = listItems.begin(); temp != listItems.end(); temp++)
	{
		if (!(*temp)->getActive() || !(*temp)->getItem()->getActive()) continue;

		Vec2 itemInBoxPosition = (*temp)->getItem()->getPosition();
		Rect itemInBoxBound = (*temp)->getItem()->getRect();
		Vec2 velocity = (*temp)->getItem()->getVeloc();

		Direction dir;

		for (std::vector<LuckyBox*>::iterator item = listItems.begin(); item != listItems.end(); item++)
		{
			Vec2 boxPosition = (*item)->getBox()->getPosition();
			Rect boxBound = (*item)->getBox()->getRect();

			dir = g_isCollide(Rect(itemInBoxPosition.x, itemInBoxPosition.y, itemInBoxBound.width, itemInBoxBound.height), Rect(boxPosition.x, boxPosition.y, boxBound.width, boxBound.height), (*temp)->getItem()->getVeloc());
			if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				itemInBoxPosition.y = boxPosition.y - itemInBoxBound.height;
			}
			else if (dir == Direction::DIR_LEFT)
			{
				itemInBoxPosition.x = boxPosition.x - itemInBoxBound.width;
				velocity.x *= -1;
			}
			else if (dir == Direction::DIR_RIGHT)
			{
				itemInBoxPosition.x = boxPosition.x + boxBound.width;
				velocity.x *= -1;
			}

			(*temp)->getItem()->setVeloc(velocity.x, velocity.y);
			(*temp)->getItem()->setPosition(itemInBoxPosition.x, itemInBoxPosition.y);
		}


		//
		for (std::vector<InformationObject>::iterator curInformationObjects = listObjects.begin(); curInformationObjects != listObjects.end(); curInformationObjects++)
		{
			InformationObject x = *curInformationObjects;

			dir = g_isCollide(Rect(itemInBoxPosition.x, itemInBoxPosition.y, itemInBoxBound.width, itemInBoxBound.height), x.m_rect, (*temp)->getItem()->getVeloc());
			if (dir == Direction::DIR_TOP || dir == Direction::DIR_TOP_LEFT || dir == Direction::DIR_TOP_RIGHT)
			{
				itemInBoxPosition.y = x.m_rect.y - itemInBoxBound.height;
				//velocity.y = 0;
			}
			else if (dir == Direction::DIR_LEFT)
			{
				itemInBoxPosition.x = x.m_rect.x - itemInBoxBound.width;
				velocity.x *= -1;
			}
			else if (dir == Direction::DIR_RIGHT)
			{
				itemInBoxPosition.x = x.m_rect.x + x.m_rect.width;
				velocity.x *= -1;
			}

			(*temp)->getItem()->setVeloc(velocity.x, velocity.y);
			(*temp)->getItem()->setPosition(itemInBoxPosition.x, itemInBoxPosition.y);
		}


		dir = g_isCollide(Rect(marioPosition.x, marioPosition.y, marioBound.width, marioBound.height), Rect(itemInBoxPosition.x, itemInBoxPosition.y, itemInBoxBound.width, itemInBoxBound.height), m_mario->getVeloc(), (*temp)->getItem()->getVeloc());
		if (dir != Direction::DIR_NONE && dir != Direction::DIR_UNKNOWN)
		{
			(*temp)->getItem()->setCollision(true);
			(*temp)->getItem()->setFinishAnimation(true);
			switch ((*temp)->getType())
			{
			case ItemsType::IT_GUN:
				m_mario->setCanShoot(true);
				break;
			case ItemsType::IT_MUSHROOM_BIGGER:
				m_mario->setIsBig(true);
				break;
			case ItemsType::IT_STAR:
				break;
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