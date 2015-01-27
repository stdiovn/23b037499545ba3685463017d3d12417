#include "stdafx.h"
#include "ItemsOwnedState.h"

IdleBox* IdleBox::m_instance = 0;

IdleBox* IdleBox::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new IdleBox();
	}

	return m_instance;
}

void IdleBox::enter(Box* item)
{
	if (item->getCoinInBox() == 0)
		item->setCurrentFrame(TileSetSheet::TS_BRICK - 1);
	else
		item->setCurrentFrame(TileSetSheet::TS_LUCKYBOX);

	item->setCollsion(false);
}

void IdleBox::execute(Box* item)
{
	if (item->getCollision() && item->getCoinInBox() != 0)
	{
		item->getStateMachine()->changeState(LuckyBoxEffect::getInstance());
		
		item->setCoinInBox(item->getCoinInBox() - 1);
	}
}

void IdleBox::exit(Box* item)
{
}

//// not yet
IdleBrick* IdleBrick::m_instance = 0;

IdleBrick* IdleBrick::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new IdleBrick();
	}

	return m_instance;
}

void IdleBrick::enter(Box* item)
{
	item->setCurrentFrame(TileSetSheet::TS_BRICK);

	item->setCollsion(false);
}

void IdleBrick::execute(Box* item)
{
	if (item->getCollision() && item->getCoinInBox() != 0)
	{
		//item->getStateMachine()->changeState(BreakBrick::getInstance());
		item->setActive(false);
	}
}

void IdleBrick::exit(Box* item)
{
}


///// effect when box is collided
LuckyBoxEffect* LuckyBoxEffect::m_instance = 0;

LuckyBoxEffect* LuckyBoxEffect::getInstance()
{
	if (m_instance == NULL)
		m_instance = new LuckyBoxEffect();

	return m_instance;
}

void LuckyBoxEffect::enter(Box* item)
{
	item->setTimeAnimation(8);
}

void LuckyBoxEffect::execute(Box* item)
{
	int time = item->getTimeAnimation();
	if (time > 0)
	{
		Vec2 position = item->getPosition();

		if (time > 4)
			position.y -= 2;
		else
			position.y += 2;

		item->setPosition(position.x, position.y);
	}
	else
	{
		item->getStateMachine()->changeState(IdleBox::getInstance());
	}

	item->setTimeAnimation(--time);
}

void LuckyBoxEffect::exit(Box* item)
{
	item->setFinishAnimation(true);
}


///-----------------------------------------------------Effect item----------------------------------
// effect items in box

Coin* Coin::m_instance = 0;

Coin* Coin::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new Coin();
	}

	return m_instance;
}

void Coin::enter(ItemInBox* item)
{
	item->setCurrentFrame(ItemSheet::IS_COIN);
	item->setTimeAnimation(16);
}

void Coin::execute(ItemInBox* item)
{
	int time = item->getTimeAnimation();

	if (item->getActive())
	{
		if (time > 0)
		{
			Vec2 posotion = item->getPosition();
			posotion.y -= 5;

			item->setPosition(posotion.x, posotion.y);
			item->setTimeAnimation(--time);
		}
		else
		{
			item->getStateMachine()->GetCurrentState()->exit(item);
		}
	}
}

void Coin::exit(ItemInBox* item)
{
	item->setFinishAnimation(true);
	item->setActive(false);
}

//
MushRoomBigger* MushRoomBigger::m_instance = 0;

MushRoomBigger* MushRoomBigger::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MushRoomBigger();
	}

	return m_instance;
}

void MushRoomBigger::enter(ItemInBox* item)
{
	item->setCurrentFrame(ItemSheet::IS_MUSHROOM_BIGGER);
	item->setTimeAnimation(8);
}

void MushRoomBigger::execute(ItemInBox* item)
{
	if (item->getActive())
	{
		int time = item->getTimeAnimation();

		Vec2 posotion = item->getPosition();

		if (time > 0)
		{
			posotion.y -= 4;
			item->setTimeAnimation(--time);
		}
		else
		{
			item->getStateMachine()->changeState(MushRoomBiggerMoving::getInstance());
		}
		item->setPosition(posotion.x, posotion.y);
	}
}

void MushRoomBigger::exit(ItemInBox* item)
{
}

/////
MushRoomBiggerMoving* MushRoomBiggerMoving::m_instance = 0;

MushRoomBiggerMoving* MushRoomBiggerMoving::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MushRoomBiggerMoving();
	}

	return m_instance;
}

void MushRoomBiggerMoving::enter(ItemInBox* item)
{
	item->setVeloc(4, 4);
}

void MushRoomBiggerMoving::execute(ItemInBox* item)
{
	if (item->getElapseTime() < 1000 / FPS * 1.5) return;
	item->updateTime();

	if (item->getActive())
	{
		Vec2 position = item->getPosition();
		Vec2 velocity = item->getVeloc();
		position += velocity;
		
		item->setPosition(position.x, position.y);
		if (item->getCollision())
		{
			item->setActive(false);
			item->setCollision(false);
		}
			
	}
}

void MushRoomBiggerMoving::exit(ItemInBox* item)
{
}


///// Brick break not yet

BreakBrick* BreakBrick::m_instance = 0;

BreakBrick* BreakBrick::getInstance()
{
	if (m_instance == NULL)
		m_instance = new BreakBrick();

	return m_instance;
}

void BreakBrick::enter(ItemInBox* item)
{
	m_timeAnimation = 8;
	m_position = item->getPosition();
}

void BreakBrick::execute(ItemInBox* item)
{
	if (m_timeAnimation > 0)
	{
	}
}

void BreakBrick::exit(ItemInBox* item)
{

}

/////////////
Gun* Gun::m_instance = 0;

Gun* Gun::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new Gun();
	}

	return m_instance;
}

void Gun::enter(ItemInBox* item)
{
	item->setCurrentFrame(ItemSheet::IS_GUNFLOWER);
	item->setTimeAnimation(8);
}

void Gun::execute(ItemInBox* item)
{
	if (item->getActive())
	{
		int time = item->getTimeAnimation();

		Vec2 posotion = item->getPosition();

		if (time > 0)
		{
			posotion.y -= 4;
			item->setTimeAnimation(--time);

			item->setPosition(posotion.x, posotion.y);
		}

		if (item->getCollision())
		{
			item->setActive(false);
			item->setCollision(false);
		}
	}
}

void Gun::exit(ItemInBox* item)
{
}

