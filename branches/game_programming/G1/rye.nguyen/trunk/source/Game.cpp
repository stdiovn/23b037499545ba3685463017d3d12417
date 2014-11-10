#include "stdafx.h"

#include "EntityManager.h"
#include "Factory.h"

#include "RenderSystem.h"

#include "Game.h"
#include <time.h>

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	m_map = new Map();
	m_map->Init();
	m_map->LoadMap(1);
	
	m_offset_position = 0;
	m_map_offset = 0;

	EntityManager::GetInstance()->AddEntity(CREATE_MUSHROOM);

	return errCode;
}

void Game::Update(float deltaTime)
{
	if(getKeyState(KeyCode::KEY_LEFT) && m_map_offset > 0)
		m_map_offset--;
	else if(getKeyState(KeyCode::KEY_RIGHT) && m_map_offset < 60 - 1)
		m_map_offset++;

	//if(m_offset_position < -20)
	//{
	//	m_offset_position = 0;
	//	//if(m_map_offset > 0)
	//		m_map_offset--;
	//}
	//else if(m_offset_position > 20)
	//{
	//	m_offset_position = 0;
	//	//if(m_map_offset < 60 - 1)
	//		m_map_offset++;
	//}

	if(1000.0f / FRAME_RATE > deltaTime)
		Sleep(1000.0f / FRAME_RATE - deltaTime);
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();

	m_map->Render(g, m_map_offset, m_offset_position);

	//RenderSystem::GetInstance()->Render(g);
}

void Game::Exit()
{

}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
int main()
{
	srand((unsigned)time(NULL));

	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Rye's Game");

	g.Run();

	return 0;
}