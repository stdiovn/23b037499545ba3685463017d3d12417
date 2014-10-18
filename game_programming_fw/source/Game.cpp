#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "Game.h"

#include "BackGround.h"

#include "Ball.h"
#include "BackGround.h"
#include "ImageSource.h"
#include "ThanhMove.h"

#define FPS 30
#define FileMap1 "data//Map_1.txt"
#define FileMap2 "data//Map_2.txt"


BackGround *Map1 = NULL;
BackGround *Map2 = NULL;

BackGround *RunMap = NULL;

ThanhMove *Space = NULL;
Ball *ball = NULL;

Game::Game()
{
	
}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	ImageSource::GetInstance()->LoadImageSource();

	Map1 = new BackGround(FileMap1);
	Map2 = new BackGround(FileMap2);
	RunMap = Map1;

	Space = new ThanhMove();
	ball = new Ball();

	return errCode;
}

void Game::Update(float deltaTime)
{
	float last = GetTickCount();
	float curren;
	do
	{
		curren = GetTickCount();
	} while (curren - last + deltaTime < (float)1000 / FPS);


	if (getKeyState(KeyCode::KEY_RIGHT) == KeyState::KEY_PRESSED)
	{
		Space->Update(KeyCode::KEY_RIGHT);
	}
	else if (getKeyState(KeyCode::KEY_LEFT) == KeyState::KEY_PRESSED)
	{
		Space->Update(KeyCode::KEY_LEFT);
	}
	else
		Space->Update(KeyCode::KEY_UNKNOWN);
	

	for (int i = 0; i < RunMap->m_FrameOnject.size(); i++)
	{
		if (RunMap->m_isDraw[i])
		{
			int left = RunMap->m_FrameOnject[i].X;
			int right = left + RunMap->GetWall(i)->GetImage()->getWidth();
			int top = RunMap->m_FrameOnject[i].Y;
			int bottom = top + RunMap->GetWall(i)->GetImage()->getHeight();

			if (ball->IsCollisionWithRect(left, right, top, bottom))
			{
				ball->SetDIR(ball->Orientation(left, right, top, bottom));
				RunMap->m_isDraw[i] = RunMap->GetWall(i)->GetActionDraw();
				break;
			}
		}
	}

	if (ball->IsCollisionWithRect(Space->m_Left, Space->m_Right, Space->m_Top, Space->m_Bottom))
	{
		ball->SetDIR(ball->Orientation(Space->m_Left, Space->m_Right, Space->m_Top, Space->m_Bottom));
	}

	ball->Update();
	RunMap->Update();

	if (RunMap->NextBackGround())
	{
		RunMap = Map2;
	}
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0x00FF00FF);

	g->drawImage(RunMap->m_BackGround, 0, 0);

	for (int i = 0; i < RunMap->m_FrameOnject.size(); i++)
	{
		if (RunMap->m_isDraw[i])
			g->drawImage(RunMap->GetWall(i)->GetImage(), RunMap->m_FrameOnject[i].X, RunMap->m_FrameOnject[i].Y);
	}

	g->drawImage(ball->GetImage(), ball->m_Left, ball->m_Top);
	g->drawImage(Space->GetImage(), Space->m_Left, Space->m_Top);
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