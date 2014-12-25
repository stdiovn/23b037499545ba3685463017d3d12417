#include "stdafx.h"

#include "Game.h"
#include "Resources.h"
#include "Background.h"
#include "Ball.h"
#include "Bar.h"
#include "NormalBrick.h"
#include "Collision.h"

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
	m_Ball = new Ball(Vec2(400, 350), Vec2(0.7, 0.7));
	m_Bar = new Bar(Vec2(400, 450), Vec2(2, 0));
	m_Brick = new NormalBrick(Vec2(5, 5));

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
	((Ball*)m_Ball)->CollisionBehavior(m_Brick);
	
}

void Game::render(Graphics* g)
{
	g->cleanScreen();	
	m_Background->render(g);
	m_Ball->render(g);
	m_Bar->render(g);
	m_Brick->render(g);
}

void Game::exit()
{
	
}


void Game::onKeyProc(KeyCode key, KeyState state)
{

}