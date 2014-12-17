#include "stdafx.h"
#include "Bar.h"

extern e_Direction g_directionBar;

CBar::CBar()
{
}


CBar::~CBar()
{
}

//-------------------------------------------------------------------------------//
/// @description :  Constructor.
/// @param		 :  filePath is a link to image
///					position : position of object
///					bound	 : rectangle bounding object
///	@return		 :	No
/// @warning     :
//------------------------------------------------------------------------------//
CBar::CBar(const char* filePath, s_vector2D position)
{

	m_textureVector.push_back(new Image(filePath));
	m_kindOfBall	= getNameKindOfBall(filePath);
	m_position		= position;
	m_velocity		= s_vector2D(10, 10);
	m_bound			= Rect(	m_position.X,
							m_position.Y,
							m_textureVector[m_kindOfBall]->getWidth(),
							m_textureVector[m_kindOfBall]->getHeight());
	m_direction = e_Direction::NONE_DIRECTION;
}

//-----------------------------------------------------------------------------//
/// @description : initialize resource. Exactly load image.
///	@parameter	 : Nothing
/// @return		 : ErrorCode
/// @warning	 : Careful statement goto
//-----------------------------------------------------------------------------//
ErrorCode CBar::Init()
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
void CBar::Release()
{
	for (int i = 0; i < m_textureVector.size(); i++)
	{
		Image* tempImage = m_textureVector[i];
		m_textureVector.erase(m_textureVector.begin() + i );
		delete tempImage; 
	}

}

//----------------------------------------------------------------------------//
/// update late;
//----------------------------------------------------------------------------//
void CBar::Render(Graphics* g)
{
	switch (m_kindOfBall)
	{
	case KATANA:
		g->drawImage(m_textureVector[KATANA], m_bound);
	default:
		break;
	}


}

//----------------------------------------------------------------------------//
///	@description :	update logic of bar
/// @paramerter  :	deltaTime : tim for loop
/// @return		 :	void
/// @warning	 :  No
//----------------------------------------------------------------------------//
void CBar::Update(float deltaTime)
{
	
	//------Update Keyboard--------------//
	UpdateInputHandle(deltaTime);


	// ---------------------collision with screen----------------------------//
	if (m_position.X <= POSITION_LEFT_SCREEN)  // collision with top and bot
	{
		m_position.X  = POSITION_LEFT_SCREEN;
	}
	if (m_position.X >= POSITION_RIGHT_SCREEN - m_bound.width)
	{
		m_position.X  = POSITION_RIGHT_SCREEN - m_bound.width;
	}

	//--------------update bound-------------------------//
	m_bound = Rect(m_position.X,
		m_position.Y,
		m_textureVector[m_kindOfBall]->getWidth(),
		m_textureVector[m_kindOfBall]->getHeight());

}

//--------------------------------------------------------------------------------------------------------------------------------//
/// @description: Update Input handle. Exactly we have to update keyboard
/// @parameter	: Nothing
/// @return	    	: void
/// @warning    	: No
//--------------------------------------------------------------------------------------------------------------------------------//
void CBar::UpdateInputHandle(float deltaTime)
{
	//---------------------//
	m_direction = g_directionBar;

	//---------- go left---------------------//
	if (m_direction  == e_Direction::LEFT_DIRECTION)
		m_position.X -= m_velocity.X * deltaTime / 50;
	//-----------go right-------------------//
	if (m_direction  == e_Direction::RIGHT_DIRECTION)
		m_position.X += m_velocity.X * deltaTime / 50;

	g_directionBar  = e_Direction::NONE_DIRECTION;
	m_direction		= e_Direction::NONE_DIRECTION;
}


//----------------------------------------------------------------------------------------------------------------------//
/// @description :	get name of kind of Ball
/// @parameter	 :	filePath  is string that it's decription for Ball
/// @return		 :  enum e_kindOfBall
/// @warning	 :  No
//------------------------------------------------------------------------------------------------------------------------//
e_KindOfBall CBar::getNameKindOfBall(const char* filePath)
{
	if (filePath == "Katana.png")
		return e_KindOfBall::KATANA;
}


//-------------------------------------------------------------------------------------------------------------------------//
/// @description :	get position Y
/// @parameter	 :	Nothing
/// @return		 :	int . this is poisition.Y
/// @warning	 :  No
//--------------------------------------------------------------------------------------------------------------------------//
int CBar::getPosY()
{
	return m_position.Y;
}