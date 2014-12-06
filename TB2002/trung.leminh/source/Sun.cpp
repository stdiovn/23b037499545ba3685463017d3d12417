#include "stdafx.h"
#include "CommonStructure.h"
#include "SuperMan.h"
#include "Geometry.h"
#include "MapManager.h"
#include "Sun.h"

#include "STDIO_FW\stdio_fw.h"
using namespace stdio_fw;

extern e_StateGame g_statusGame;


CSun::CSun()
{
}


CSun::~CSun()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Initialize Sun object
/// @parameter:   No
/// @return type: ErrorCode .We will know some error if image can not load or initialize.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
ErrorCode CSun::Init()
{
	m_posX = 400;
	m_posY = 300;
	m_velX = 10;
	m_velY = 10;
	m_texture = new Image("Sun.png");
	ErrorCode e = m_texture->loadImage();

	return e ;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update Sun object. Include ..
/// @parameter:   No
/// @return type: void .	
/// @warning :    If you don't release all resource of careless, this is very dangerous because perfomance of device descreased.
//---------------------------------------------------------------------------------------------------------------------------------
void CSun::Update(float deltaTime)
{
	// collision with screen
	if (m_posX <= POSITION_LEFT )  // collision with top and bot
	{
		m_posX = POSITION_LEFT;
		CHANGE_DIRECTION(m_velX);
	}
	if (m_posX >= POSITION_RIGHT - m_texture->getWidth())
	{
		m_posX = POSITION_RIGHT  - m_texture->getWidth();
		CHANGE_DIRECTION(m_velX);
	}

	if (m_posY <= POSITION_TOP) // collision with right and left
	{
		m_posY = POSITION_TOP;
		CHANGE_DIRECTION(m_velY);
	}

	if (m_posY >= POSITION_BOT - m_texture->getHeight())
	{
		m_posY = POSITION_BOT  - m_texture->getHeight();
		CHANGE_DIRECTION(m_velY);
		g_statusGame = END_GAMEOVER;
	}

	// Sun move
	m_posX += (int)(m_velX*deltaTime/50); // don't understand.
	m_posY += (int)(m_velY*deltaTime/50);
};

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update Collision with list enity in map and update collition with superMan
/// @parameter:   CMapManager* mapManager, CSuperMan* superMan
/// @return type: void
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CSun::UpdateCollision(CMapManager* mapManager, CSuperMan* superMan)
{ 
	{
		for (int i = 0; i < mapManager->getMap().m_cloud.size(); i++)
		{
			if (checkIntersectRectangle(getSizeRectOfObject(),
				mapManager->getMap().m_cloud[i]->getSizeRectOfObject()))
			{
				CHANGE_DIRECTION(m_velY);
				m_posY = (int)(mapManager->getMap().m_cloud[i]->getSizeRectOfObject().y + mapManager->getMap().m_cloud[i]->getSizeRectOfObject().height + DELTA_X);
			}
		}

		if (checkIntersectRectangle(getSizeRectOfObject(),
			superMan->getSizeRectOfObject()))
		{
			CHANGE_DIRECTION(m_velY);
			m_posY = superMan->getPosY() - m_texture->getHeight() - DELTA_Y;
		}
	}
};

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: 
/// @parameter: 
/// @return type: .	
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void CSun::UpdateEventHandle()
{

}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render Sun ..
/// @parameter:   g is Graphics varible
/// @return type: void .	
/// @warning :.
//---------------------------------------------------------------------------------------------------------------------------------
void CSun::Render(Graphics* g)
{
	static int rotation = 1;
	g->drawImage(m_texture, m_posX, m_posY, rotation);
	CHANGE_DIRECTION(rotation);
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: When game finished or we close windows, we have to release resource.
/// @parameter:  No
/// @return type:void .	
/// @warning :   If you don't release all resource of careless, this is very dangerous because perfomance of device descreased.
//---------------------------------------------------------------------------------------------------------------------------------
void CSun::Release()
{
	delete m_texture;
}
