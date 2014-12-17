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
	
	m_miniBall = new CBall(BALL_FILE_PATH, s_vector2D(400, 400));
	m_miniBall->Init();
	m_miniBar	= new CBar(BAR_FILE_PATH,  s_vector2D(400, 500));
	m_miniBar->Init();
	
	m_map = new CMapmanager();
	m_map->Init();


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
	UpdateInputHandle();
	m_miniBall	->Update(deltaTime);
	m_miniBall->UpdateCollisionWithAllthingInMap((CBar*)m_miniBar, m_map);
	m_miniBar	->Update(deltaTime);
	
	m_map->Update(deltaTime, m_miniBall);

	Sleep((DWORD)0.020); // frame honor ^^ I'm going to pro.
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
	{
		g_directionBar = e_Direction::LEFT_DIRECTION;
	}
	if (getKeyState(KEY_RIGHT))
	{
		g_directionBar = e_Direction::RIGHT_DIRECTION;
	}
}


//--------------------------------------------------------------------------------------------------------------------------------
/// @description: We are going to draw our world. We don't no couting in this funtion because this only using draw
/// @parameter:   g's Graphic variable type. Update late.
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Render(Graphics* g)
{
	g->setClearColor(0x0000FFFF);
	g->cleanScreen();
	m_miniBar	->Render(g);
	m_miniBall	->Render(g);
	m_map		->Render(g);
	
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: When game finished or we close windows, we have to release resource.
/// @parameter:   No
/// @return type: void .	
/// @warning :    If you don't release all resource of careless, this is very dangerous because perfomance of device descreased.
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Exit()
{
	m_miniBar->Release();
	m_miniBall->Release();
}