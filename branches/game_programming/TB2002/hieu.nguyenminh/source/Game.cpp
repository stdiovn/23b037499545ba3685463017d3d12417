#include "stdafx.h"

#include "Game.h"
#include "Resources.h"
#include "Background.h"
#include "Ball.h"
#include "NormalBrick.h"
#include "Collision.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);	

	InitImage();
	mBackground = new Background();
	mBall = new Ball(5, 400);
	mBrick = new NormalBrick(500, 400);

	return errCode;
}

void Game::Update(float deltaTime)
{
	if (isCollided(mBall->getBound(), mBrick->getBound()))
	{
		mBrick->Dead();
	}

	if (getKeyState(KEY_A) == KEY_PRESSED)
	{

	}

	mBall->Update(deltaTime);
	mBrick->Update(deltaTime);
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();	
	mBackground->Render(g);
	mBall->Render(g);
	mBrick->Render(g);
}

void Game::Exit()
{
	
}