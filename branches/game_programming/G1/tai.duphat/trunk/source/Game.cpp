#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"

#include "Game.h"
#include "Map1.h"
#include "Map2.h"
#define FPS 30
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#include "Ball.h"
#include "ThanhMove.h"

#define MapFile2 "Data//Map_2.txt"
#define MapFile "Data//Map_1.txt"
#include "StateManager.h"
#include "TileMap.h"
StateManager *m_State;

MapObject *state = NULL;

MapObject *state1 = NULL;
MapObject *state2 = NULL;
Ball *ball = NULL;
ThanhMove *Space = NULL;

TileMap *tileMap = NULL;

Game::Game()
{

}

Game::~Game()
{
	/*ball->Clear();
	state1->Clear();
	state2->Clear();
	Space->Clear();*/

	delete tileMap;
}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	/*ball = new Ball();
	ball->setPosition(100, 300);

	state1 = new Map1();
	state1->InitMap(MapFile);

	state2 = new Map2();
	state2->InitMap(MapFile2);

	state = state1;

	Space = new ThanhMove(100, 450);

	m_State = new StateManager();
	m_State->switchState(StateMap::MenuState);*/

	tileMap = new TileMap("Data//TileMap.txt");
	return errCode;
}

void Game::Update(float deltaTime)
{
	// set gamerun with time 1000 / fps (ms)
	float lasttime = GetTickCount();
	float current;
	do
	{
		current = GetTickCount();
	} while (current - lasttime + deltaTime < (float)1000 / FPS);

	/*if (state->NextMap())
	{
		state = state1;
	}

	if (ball->UpdateCollisionWindows(SCREEN_WIDTH, SCREEN_HEIGHT) == DIR::ABOVE)
	{
		state->setIsActive(false);
	}

	Space->UpdateCollisionWithWindows(SCREEN_WIDTH, SCREEN_HEIGHT);

	for (int i = 0; i < state->getCountFrameWallOnMap(); i++)
	{
		Object temp = state->getPosition(i);
		if (state->isActiveRenderAt(i) && ball->isCollsionObject(temp.X, temp.X + state->getWidth(i), temp.Y, temp.Y + state->getHeight(i)))
		{
			ball->UpdateVeclocity(temp.X, temp.X + state->getWidth(i), temp.Y, temp.Y + state->getHeight(i));
			state->deActiveRenderAt(i);
			break;
		}
	}

	if (ball->isCollsionObject(Space->getPositionX(), Space->getPositionX() + Space->getWidth(), Space->getPositionY(), Space->getPositionY() + Space->getHeight()))
	{
		ball->UpdateVeclocity(Space->getPositionX(), Space->getPositionX() + Space->getWidth(), Space->getPositionY(), Space->getPositionY() + Space->getHeight());
	}

	if (getKeyState(KEY_LEFT) == KeyState::KEY_PRESSED)
	{
		Space->UpdateSpeedKeyBoard(KEY_LEFT);
	}
	else if (getKeyState(KEY_RIGHT) == KeyState::KEY_PRESSED)
	{
		Space->UpdateSpeedKeyBoard(KEY_RIGHT);
	}

	ball->Update();*/
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0x00FF00FF);

	tileMap->Render(g);
	/*state->Render(g);

	if (state->isGameOver()) return;

	ball->Render(g);
	Space->Render(g);*/
	//m_State->renderState(g);
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
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");

	g.Run();
}