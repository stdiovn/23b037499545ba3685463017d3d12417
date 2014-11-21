#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "Game.h"


#define FPS 30
#include "System.h"

Entity *Font;
Entity *Animation;
Game::Game()
{
}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);
	
	Font = new Entity();

	Component *position = new Position(100, 100);
	Font->addComponent(position, IDComponent::COM_POSITION);
	Font->addComponent(new FontComponent("Data//Font//Font.map", "STDIO"), IDComponent::COM_FONT);

	//------Animation

	Animation = new Entity();
	Animation->addComponent(new Position(100, 200), IDComponent::COM_POSITION);
	Animation->addComponent(new SpriteComponent("Data//Contra.png", 5, 5), IDComponent::COM_SPRITE);
	return errCode;
}

void Game::Update(float deltaTime)
{
	float lasttime = GetTickCount();
	float current;
	do
	{
		current = GetTickCount();
	} while (current - lasttime + deltaTime < 1000 / FPS);

}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0x00FF00FF);

	RenderFontSystem(g, Font);
	RenderAnimationSystem(g, Animation);
}

void Game::Exit()
{
	Font->ClearAll();
	Animation->ClearAll();
}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.Init(600, 480, "Game");

	g.Run();
}