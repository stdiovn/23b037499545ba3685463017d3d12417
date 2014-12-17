#include "stdafx.h"
#include "Stone.h"


CStone::CStone()
{
}


CStone::~CStone()
{
}

//-------------------------------------------------------------------------------//
/// @description :  Constructor.
/// @param		 :  filePath is a link to image. we have 2 filePath because we have two state for stone. begin stone have state : e_StateBrick::STONE_BRICK, when bar colission with it. it change state became WOOD_BRICK
///					position : position of object
///	@return		 :	No
/// @warning     :
//------------------------------------------------------------------------------//
CStone::CStone(const char* filePath, const char* filePath2, s_vector2D position)
{
	m_textureVector.push_back(new Image(filePath));
	m_textureVector.push_back(new Image(filePath2));
	m_healthyBrick	= e_StateBrick::STONE_BRICK_STATE; // update late
	m_position		= position;
	m_velocity		= s_vector2D(0, 0);
	m_bound			= Rect(	m_position.X,
							m_position.Y,
							m_textureVector[STONE_BRICK_STATE]->getWidth(),
							m_textureVector[STONE_BRICK_STATE]->getHeight());
}

//-----------------------------------------------------------------------------//
/// @description : initialize resource. Exactly load image.
///	@parameter	 : Nothing
/// @return		 : ErrorCode
/// @warning	 : Nothing to say
//-----------------o------------------------------------------------------------//
ErrorCode CStone::Init()
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

//---------------------------------------------------------------------//
/// @description :	Update Stone. Exactly update position and size
/// @param		 :	time for update
/// @return		 :	void
/// @warning	 :	No
//--------------------------------------------------------------------//
void CStone::Update(float deltaTime)
{
	m_bound = Rect(	m_position.X,
					m_position.Y,
					m_textureVector[m_healthyBrick]->getWidth(),
					m_textureVector[m_healthyBrick]->getHeight());
}

//-------------------------------------------------------------------//
/// @description :	Release resource image
/// @param		 : No
/// @return		 : void
/// @warning	 : No
//--------------------------------------------------------------------//
void CStone::Release()
{
	for (int i = 0; i < m_textureVector.size(); i++)
	{
		Image* tempImage = m_textureVector[i];
		m_textureVector.erase(m_textureVector.begin() + i);
		delete tempImage;
	}
}

//--------------------------------------------------------------------//
/// @description :	Render object to map
/// @param		 :	Graphics* g:
/// @return		 :	void
/// @warning	 :  No
//--------------------------------------------------------------------//
void CStone::Render(Graphics* g)
{
	if (!m_textureVector.empty())
		g->drawImage(m_textureVector[m_healthyBrick], m_bound);
}