#include "stdafx.h"
#include "Game.h"
#include "CommonStructure.h"

//----------------global variable-----------------------//
e_Direction g_directionBar;		// using connect information 2 object file.
//-----------------------------------------------------//

Game::Game()
{

}

Game::~Game()
{

}
	

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: initialize  Game data.
/// @parameter:   screenW and screenH : size Widht and Height of windows
///				  title				: name of Windows.
/// @return type: ErrorCode. This is enum to descreption some error when we create windows 
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);
	m_Image = new Image("SpriteShipMario.png");
	errCode = m_Image->loadImage();
	if (errCode != ErrorCode::ERR_NO_ERROR)
		MessageBox(NULL, "Can not open file image", NULL, MB_OK);

	m_direction = e_Direction::NONE_DIRECTION;
	m_position	= s_vector2D(0, 0);

	return errCode;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update scene. Do not update event handle .Because we are going to update event at UpdateEvenHandle function
/// @parameter:   deltaTime. 
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Update(float deltaTime)
{
	Sleep(80);
	UpdateInputHandle();
	switch (m_direction)
	{
	case NONE_DIRECTION:
		break;
	case LEFT_DIRECTION:
		m_position.X	-= 16;
		m_direction		= NONE_DIRECTION;
		m_flip			= 0x1L;
		m_index--;
		break;
	case RIGHT_DIRECTION:
		m_position.X	+= 16;
		m_direction		= NONE_DIRECTION;
		m_index++;
		m_flip			= 0;
		break;
	case TOP_DIRECTION:
		break;
	case BOT_DIRECTION:
		break;
	default:
		break;
	}
	if (m_index < 0)
		m_index = 0;
	if (m_index > 6)
		m_index = 6;
}

//--------------------------------------------------------------------------------------------------------------------------------//
/// @description: Update Input handle. Exactly we have to update keyboard
/// @parameter	: Nothing
/// @return	    	: void
/// @warning    	: No
//--------------------------------------------------------------------------------------------------------------------------------//
void Game::UpdateInputHandle()
{
	if (getKeyState(KEY_LEFT))
		m_direction = e_Direction::LEFT_DIRECTION;
	if (getKeyState(KEY_RIGHT))
		m_direction = e_Direction::RIGHT_DIRECTION;
}	


//--------------------------------------------------------------------------------------------------------------------------------
/// @description: We are going to draw our world. We don't no couting in this funtion because this only using draw
/// @parameter:   g's Graphic variable type. Update late.
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Render(Graphics* g)
{
	g->setClearColor(0x000000FF);
	g->cleanScreen();
	printf("%d, %d", m_position.X, m_position.Y);
	g->drawRegion(	m_Image,
					Rect(	m_position.X,
							m_position.Y,
							32,
							64),
					Rect(	m_position.X,
							m_position.Y,
							16,
							32),
					m_flip
				);
	
	
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: When game finished or we close windows, we have to release resource.
/// @parameter:   No
/// @return type: void .	
/// @warning :    If you don't release all resource of careless, this is very dangerous because perfomance of device descreased.
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Exit()
{
	delete m_Image;
}