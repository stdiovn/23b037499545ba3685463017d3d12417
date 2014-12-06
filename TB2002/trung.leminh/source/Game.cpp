#include "stdafx.h"

#include "Game.h"
#include "Cloud.h"
#include "Sun.h"


e_Direction g_moveDirection = NONE;
e_StateGame	g_statusGame = START;

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
	
	//-----------scene-------------------//
	m_mapManager		= new CMapManager();
	m_mapManager		->Init();
	//-----------------------------------//

	m_sun				= new CSun();
	m_sun				->Init();

	m_superMan			= new CSuperMan();
	m_superMan			->Init();

	g_statusGame		= START;
	m_congtratulation	= new Image("Finish.png");
	m_congtratulation	->loadImage();
	m_gameOver			= new Image("GameOver.png");
	m_gameOver			->loadImage();
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
	m_sun			->Update(deltaTime);
	m_superMan		->Update(deltaTime);
	m_sun->UpdateCollision(m_mapManager, m_superMan);
	m_mapManager	->Update(m_sun);
	
	

	//-----------STUPID CODE---------------------------//
	// temp and stupid. But i will repair it.
	if (getKeyState(KEY_RIGHT))
	{
		g_moveDirection = RIGHT;
	}
	if (getKeyState(KEY_LEFT))
	{
		g_moveDirection = LEFT;
	}
	//--------------------------------------------------//

	Sleep((DWORD)0.020); // frame honor ^^ I'm going to pro.
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: We are going to draw our world. We don't no couting in this funtion because this only using draw
/// @parameter:   g's Graphic variable type. Update late.
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Render(Graphics* g)
{
	if (g_statusGame == START){
		g->setClearColor(0xFFFFFFFF);
		g->cleanScreen();

		m_mapManager->Render(g);
		m_sun->Render(g);
		m_superMan->Render(g);
	}
	if (g_statusGame == END_GAMEOVER)
	{
		g->drawImage(m_gameOver, Rect(0, 0, m_gameOver->getWidth(), m_gameOver->getHeight()), 0);
	}

	if (g_statusGame == END_CONGTRATULATION)
	{
		g->drawImage(m_congtratulation, Rect(0, 0, m_congtratulation->getWidth(), m_congtratulation->getHeight()), 0);

	}
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: When game finished or we close windows, we have to release resource.
/// @parameter:   No
/// @return type: void .	
/// @warning :    If you don't release all resource of careless, this is very dangerous because perfomance of device descreased.
//---------------------------------------------------------------------------------------------------------------------------------
void Game::Exit()
{
	m_sun		->Release();
	m_superMan	->Release();
	m_mapManager->Release();
}