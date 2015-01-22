#include "stdafx.h"
#include "ItemInBox.h"
#include "ItemsOwnedState.h"

ItemInBox::ItemInBox(Image* spritesheet, std::vector<Frame>* frameList, ItemsType type) : BaseObject(spritesheet, frameList)
{
	m_type = type;
	m_isActive = false;
	m_stateMachine = new StateMachine<ItemInBox>(this);

	switch (type)
	{
	case IT_COIN:
		m_currentFrame = ItemSheet::IS_COIN;
		m_stateMachine->changeState(Coin::getInstance());
		break;
	case IT_MUSHROOM_BIGGER:
		m_currentFrame = ItemSheet::IS_MUSHROOM_BIGGER;
		m_stateMachine->changeState(MushRoomBigger::getInstance());
		break;
	case IT_GUN:
		m_currentFrame = ItemSheet::IS_GUNFLOWER;
		break;
	case IT_STAR:
		m_currentFrame = ItemSheet::IS_STAR;
		break;
	case IT_MUSHROOM_UP:
		m_currentFrame = ItemSheet::IS_MUSHROOM_UP;
		break;
	case IT_BRICK:
		m_currentFrame = ItemSheet::IS_BREAKBRICK;
		m_stateMachine->changeState(BreakBrick::getInstance());
		break;
	}
}


ItemInBox::~ItemInBox()
{
	
}


void ItemInBox::update()
{
	if (m_stateMachine && m_isActive)
		m_stateMachine->update();
}

void ItemInBox::draw(Graphics* g)
{
	if (m_isActive)
	{
		Mat3 matrix;
		matrix.setTranslation(m_vpx, m_vpy);
		Vec3 vector(m_position.x, m_position.y, 1);
		vector = vector *  matrix;

		g->drawRegion(m_spriteSheet,
			Rect(vector.x, vector.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height),
			m_frameList->at(m_currentFrame).m_frameRect,
			FLIP_NONE);
	}
}

void ItemInBox::setCamera(int vpx, int vpy)
{
	m_vpx = vpx;
	m_vpy = vpy;
}