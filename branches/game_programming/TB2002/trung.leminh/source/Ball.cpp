#include "stdafx.h"
#include "Ball.h"
#include "CommonStructure.h"
#include "Geometry.h"

CBall::CBall()
{
}


CBall::~CBall()
{
}
//------------------------------------------------------------------//
///	@description :	Constructor.
/// @param		 :  filePath is a link to image
///					position : position of object
///					bound	 : rectangle bounding object
///	@return		 :	No
/// @warning     :
//------------------------------------------------------------------------------//
CBall::CBall(const char* filePath, s_vector2D position)
{
	m_textureVector.push_back(new Image(filePath));
	m_stateBall = getNameStateBall(filePath);
	m_position	= position;
	m_velocity  = s_vector2D(10, 10);
	m_bound		= Rect(	m_position.X,
						m_position.Y,
						m_textureVector[m_stateBall]->getWidth(),
						m_textureVector[m_stateBall]->getHeight());

}

//-----------------------------------------------------------------------------//
/// @description : initialize resource. Exactly load image.
///	@parameter	 : Nothing
/// @return		 : ErrorCode
/// @warning	 : Careful statement goto
//-----------------------------------------------------------------------------//
ErrorCode CBall::Init()
{
	ErrorCode err;
	for (int i = 0; i < m_textureVector.size(); i++)
	{
		err = m_textureVector[i]->loadImage();
		if (err != ErrorCode::ERR_NO_ERROR)
			exit(0);
	}
	return err;
}

//-----------------------------------------------------------------------------//
///	@description :	Release resource. specific we release texture in vector.
///	@parameter	 :	No
/// @return		 :  void
/// @warning	 :	more Careful
//-----------------------------------------------------------------------------//
void CBall::Release()
{
	for (int i = 0; i < m_textureVector.size(); i++)
	{
		Image* tempImage = m_textureVector[i];
		m_textureVector.erase(m_textureVector.begin() + i);
		delete tempImage;
	}
}

//-----------------------------------------------------------------------------//
//-----------------------------------------------------------------------------//
void CBall::Render(Graphics* g)
{
	switch (m_stateBall)
	{
	case STAND_BALL:
		g->drawImage(m_textureVector[STAND_BALL], m_bound, 1);
	default:
		break;
	}
		
}

//-----------------------------------------------------------------------------//
//-----------------------------------------------------------------------------//
void CBall::Update(float deltaTime)
{
	// ---------------------collision with screen----------------------------//
	if (m_position.X <= POSITION_LEFT_SCREEN)  // collision with top and bot
	{
		m_position.X  = POSITION_LEFT_SCREEN;
		CHANGE_DIRECTION(m_velocity.X);
	}
	if (m_position.X >= POSITION_RIGHT_SCREEN - m_bound.width)
	{
		m_position.X  = POSITION_RIGHT_SCREEN - m_bound.width;
		CHANGE_DIRECTION(m_velocity.X);
	}

	if (m_position.Y <= POSITION_TOP_SCREEN) // collision with right and left
	{
		m_position.Y  = POSITION_TOP_SCREEN;
		CHANGE_DIRECTION(m_velocity.Y);
	}

	if (m_position.Y >= POSITION_BOT_SCREEN - m_bound.height)
	{
		m_position.Y  = POSITION_BOT_SCREEN - m_bound.height;
		CHANGE_DIRECTION(m_velocity.Y);
	}
	//--------------------------------------------------------------------------//
	// Ball move
	m_position.X += (int)(m_velocity.X*deltaTime / 50); // don't understand.
	m_position.Y += (int)(m_velocity.Y*deltaTime / 50);

	//--------------update bound-------------------------//
	m_bound = Rect(m_position.X,
		m_position.Y,
		m_textureVector[m_stateBall]->getWidth(),
		m_textureVector[m_stateBall]->getHeight());


}

void CBall::UpdateCollisionWithAllthingInMap(CBar* bar, CMapmanager* map)
{
	//-------------------Update with Ball---------------------------------//
	if (checkIntersectRectangle(m_bound,
			bar->getSizeRectOfObject()))
	{
		CHANGE_DIRECTION(m_velocity.Y);
		m_position.Y = bar->getPosY() - m_textureVector[0]->getHeight() - DELTA_Y;
	}
	//--------------------------------------------------------------------//

	for (int i = 0; i < map->getMap().m_brick.size(); i++)
	{
		if (checkIntersectRectangle(getSizeRectOfObject(),
			map->getMap().m_brick[i]->getSizeRectOfObject()))
		{
			CHANGE_DIRECTION(m_velocity.Y);
			m_position.Y = (int)(map->getMap().m_brick[i]->getSizeRectOfObject().y + map->getMap().m_brick[i]->getSizeRectOfObject().height + DELTA_Y);
		}
	}
}

e_StateBall CBall::getNameStateBall(const char* filePath)
{
	if (filePath == "Suriken.png")
		return e_StateBall::STAND_BALL;
}