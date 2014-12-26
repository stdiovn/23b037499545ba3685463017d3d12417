#include "stdafx.h"

#include "Game.h"
#include "Resources.h"
#include "Background.h"
#include "Ball.h"
#include "Bar.h"
#include "NormalBrick.h"
#include "Collision.h"
#include "BrickVector.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::init(screenW, screenH, title);	

	InitImage();
	m_Background = new Background();
	m_Ball = new Ball(Vec2(400, 350), Vec2(0.4, 0.4));
	m_Bar = new Bar(Vec2(400, 500), Vec2(2, 0));
	m_BrickVector = new BrickVector();
	m_BrickVector->createNormalBrickMap(30, Vec2(5, 5), 5, 5);

	return errCode;
}

void Game::update(float deltaTime)
{
	if (getKeyState(KEY_LEFT) == KEY_PRESSED)
	{
		((Bar*)m_Bar)->moveLeft(deltaTime);
	}

	if (getKeyState(KEY_RIGHT) == KEY_PRESSED)
	{
		((Bar*)m_Bar)->moveRight(deltaTime);
	}

	m_Ball->update(deltaTime);
	((Ball*)m_Ball)->CollisionBehavior(m_Bar);
	m_BrickVector->CollisionBehaviorwithBall((Ball*)m_Ball);
	
}

void Game::render(Graphics* g)
{
	g->cleanScreen();	
	m_Background->render(g);
	m_Ball->render(g);
	m_Bar->render(g);
	m_BrickVector->render(g);
}

void Game::exit()
{
	
}


void Game::onKeyProc(KeyCode key, KeyState state)
{

}