#include "stdafx.h"
#include "Brick.h"


CBrick::CBrick()
{
}


CBrick::~CBrick()
{
}

s_vector2D CBrick::getPosition()
{
	return m_position;
}

void CBrick::setPosition(s_vector2D position)
{
	m_position = position;
}

e_StateBrick CBrick::getStateBrick()
{ 
	return m_healthyBrick;
}

void CBrick::setStateBrick(e_StateBrick stateBrick)
{
	m_healthyBrick = stateBrick;
}