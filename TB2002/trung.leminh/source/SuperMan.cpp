#include "stdafx.h"
#include "SuperMan.h"
#include "CommonStructure.h"

extern e_Direction			g_moveDirection;

CSuperMan::CSuperMan()
{
}


CSuperMan::~CSuperMan()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Initialize Sun object
/// @parameter:   No
/// @return type: ErrorCode .We will know some error if image can not load or initialize.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
ErrorCode CSuperMan::Init()
{
	m_posX		= 400;
	m_posY		= 525;
	m_velX		= 10;
	m_velY		= 10;
	m_texture	= new Image("SuperMan.png");
	ErrorCode e = m_texture->loadImage();

	g_moveDirection = NONE;

	return e;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update SuperMan object
/// @parameter:   deltaTime.it's float.
/// @return type: void .
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CSuperMan::Update(float deltaTime)
{
	UpdateEventHandle();

	if (g_moveDirection == LEFT)
	{
		m_posX -= (int)(m_velX*deltaTime / 50);
	}
		
	if (g_moveDirection == RIGHT)
	{
		m_posX += (int)(m_velX*deltaTime / 50);
	}
		

	if (m_posX <= POSITION_LEFT)
		m_posX  = POSITION_LEFT;
		
	if (m_posX >= POSITION_RIGHT - m_texture->getWidth())
		m_posX  = POSITION_RIGHT - m_texture->getWidth();

	g_moveDirection = NONE;
}

void CSuperMan::UpdateEventHandle()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render SuperMan object
/// @parameter:   g. g is Graphics type. Graphics type is type for stdio
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CSuperMan::Render(Graphics* g)
{
	g->drawImage(m_texture, m_posX, m_posY, 0);
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Release resource. In this object. we have to release m_texture
/// @parameter:   No
/// @return type: void.
/// @warning :	  Alway remember it
//---------------------------------------------------------------------------------------------------------------------------------
void CSuperMan::Release()
{
	delete m_texture;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: When i have been worked, i have get infomation positionY of SuperMan. This function help me this thing
/// @parameter:   No
/// @return type: int. This is Position Y of SuperMan
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
int CSuperMan::getPosY()
{
	return m_posY;
}