#include "stdafx.h"
#include "Wood.h"
#include "CommonStructure.h"

CWood::CWood()
{
}


CWood::~CWood()
{
}

//-------------------------------------------------------------------------------//
/// @description :  Constructor.
/// @param		 :  filePath is a link to image
///	                position : position of object
///					bound	 : rectangle bounding object
///	@return		 :	No
/// @warning     :
//------------------------------------------------------------------------------//
CWood::CWood(const char* filePath, s_vector2D position)
{
	m_textureVector.push_back(new Image(filePath));
	m_healthyBrick	= e_StateBrick::WOOD_BRICK_STATE; // update late
	m_position		= position;
	m_velocity		= s_vector2D(0, 0);
	m_bound			= Rect(	m_position.X,
							m_position.Y,
							m_textureVector[WOOD_BRICK_STATE]->getWidth(),
							m_textureVector[WOOD_BRICK_STATE]->getHeight());
}

//-----------------------------------------------------------------------------//
/// @description : initialize resource. Exactly load image.
///	@parameter	 : Nothing
/// @return		 : ErrorCode
/// @warning	 : Nothing to say
//-----------------o------------------------------------------------------------//
ErrorCode CWood::Init()
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

void CWood::Update(float deltaTime)
{
	m_bound = Rect(	m_position.X,
					m_position.Y,
					m_textureVector[m_healthyBrick]->getWidth(),
					m_textureVector[m_healthyBrick]->getHeight());
}

void CWood::Release()
{
	for (int i = 0; i < m_textureVector.size(); i++)
	{
		Image* tempImage = m_textureVector[i];
		m_textureVector.erase(m_textureVector.begin() + i);
		delete tempImage;
	}
}

void CWood::Render(Graphics* g)
{
	switch (m_healthyBrick)
	{
	case WOOD_BRICK_STATE:
		g->drawImage(m_textureVector[WOOD_BRICK_STATE], m_bound);
	default:
		break;
	}
}


