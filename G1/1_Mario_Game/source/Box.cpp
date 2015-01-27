#include "stdafx.h"
#include "ItemsOwnedState.h"
#include "Box.h"


Box::Box(Image* spritesheet, std::vector<Frame>* frameList, ItemsType type, int countCoin) : BaseObject(spritesheet, frameList)
{
	m_stateMachine = new StateMachine<Box>(this);
	m_isActive = true;
	m_countCoin = countCoin;
	m_finishAnimation = false;

	if (type == ItemsType::IT_BRICK)
	{
		m_stateMachine->changeState(IdleBrick::getInstance());
	}
	else
		m_stateMachine->changeState(IdleBox::getInstance());
}

Box::~Box()
{
	SAFE_DEL(m_stateMachine);
}

StateMachine<Box>* Box::getStateMachine()
{
	return m_stateMachine;
}

void Box::update()
{
	if (m_stateMachine)
		m_stateMachine->update();
}

void Box::draw(Graphics *g)
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
			m_flipping);
	}
}

void Box::setCamera(int x, int y)
{
	m_vpx = x;
	m_vpy = y;
}
