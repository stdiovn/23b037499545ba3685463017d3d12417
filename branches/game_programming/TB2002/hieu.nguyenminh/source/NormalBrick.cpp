#include "stdafx.h"
#include "NormalBrick.h"
#include "Resources.h"
#include "GameDefine.h"


NormalBrick::NormalBrick()
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_isDead = false;
	m_Image = &_image_NormalBrick;
	m_vx = 0;
	m_vy = 0;
}

NormalBrick::NormalBrick(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_isDead = false;
	m_Image = &_image_NormalBrick;
	m_vx = 0;
	m_vy = 0;
}


NormalBrick::~NormalBrick()
{
}

