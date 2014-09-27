#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"

#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	return errCode;
}

void Game::Update(float deltaTime)
{

}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0x00FF00FF);
	g->drawRect(50, 50, 200, 200);
}

void Game::Exit()
{

}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.Init(800, 600, "Game");

	g.Run();
}