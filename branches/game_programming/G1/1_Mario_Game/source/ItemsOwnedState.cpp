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
	m_timeAnimation = 8;
}

void LuckyBoxEffect::execute(Box* item)
{
	if (m_timeAnimation > 0)
	{
		Vec2 position = item->getPosition();

		if (m_timeAnimation > 4)
			position.y -= 2;
		else
			position.y += 2;

		item->setPosition(position.x, position.y);
	}
	else
	{
		item->getStateMachine()->changeState(IdleBox::getInstance());
	}

	m_timeAnimation--;
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
	m_timeAnimation = 16;
	m_position = item->getPosition();
}

void Coin::execute(ItemInBox* item)
{
	if (item->getActive())
	{
		if (m_timeAnimation > 0)
		{
			Vec2 posotion = item->getPosition();
			posotion.y -= 5;

			item->setPosition(posotion.x, posotion.y);
			m_timeAnimation--;
		}
		else
		{
			item->setPosition(m_position.x, m_position.y);
			item->getStateMachine()->GetCurrentState()->exit(item);
		}
	}
}

void Coin::exit(ItemInBox* item)
{
	m_timeAnimation = 16;
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
	m_timeAnimation = 8;

	m_veclocity.x = 4;
	m_veclocity.y = 4;
}

void MushRoomBigger::execute(ItemInBox* item)
{
	if (item->getActive())
	{
		Vec2 posotion = item->getPosition();

		if (m_timeAnimation > 0)
		{
			posotion.y -= 4;
			m_timeAnimation--;
		}
		else
		{

		}
		item->setPosition(posotion.x, posotion.y);
	}
}

void MushRoomBigger::exit(ItemInBox* item)
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