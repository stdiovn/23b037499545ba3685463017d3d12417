#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "Game.h"
#include "Factory.h"

#define SrcWidth 800
#define SrcHeight 600

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	m_Factory = new Factory;
	m_Factory->Init();
	EntityManager::GetInstance()->Init();
	EntityManager::GetInstance()->AddEntity(m_Factory->CreateTart());
	EntityManager::GetInstance()->AddEntity(m_Factory->CreateTurtle());
	m_Render = new RenderSystem();
	m_Move = new MovementSystem();
	m_Animation = new AnimationSystem();
	return errCode;
}
void Game::LimitFPS(int LimitFPS, float DeltaTime)
{
	int LimitFDT;
	LimitFDT = 1000 / LimitFPS;
	if ( DeltaTime < LimitFDT)
	{
		Sleep(LimitFDT - DeltaTime);
	}
}

void Game::Update(float deltaTime)
{
	//Limit FPS
	LimitFPS(60 , deltaTime);

	m_Render->Update();
	m_Move->Update();
	m_Animation->Update();
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	m_Render->Render(g);
	m_Move->Render(g);
	m_Animation->Render(g);
}

void Game::Exit()
{
	SAFE_DEL(m_Render);
	SAFE_DEL(m_Move);
	SAFE_DEL(m_Animation);
}

/////////////////////////////////////
// Entry Point

/////////////////////////////////////

void main()
{
	Game g;
	
	g.Init(SrcWidth, SrcHeight, "Game");
	g.Run();
	g.Exit();
}