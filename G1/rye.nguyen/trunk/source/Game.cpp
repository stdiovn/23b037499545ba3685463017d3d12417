#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"

#include "config.h"

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
	
	m_background = new Image("image\\background.jpg");
	m_background->loadImage();
	m_background->scale(0.5);

	m_game_over = new Image("image\\gameover.png");
	m_game_over->loadImage();

	m_is_game_over = false;

	m_count_of_brick = 45;
	m_brick = new Brick*[m_count_of_brick];

	int brick_width = 70;
	int brick_height = 20;

	for(int i = 0; i < m_count_of_brick; i++)
	{
		m_brick[i] = new Brick();
		m_brick[i]->Init(40 + (i % 9) * (brick_width + 10), 20 + (i / 9) * (brick_height + 10), brick_width, brick_height);
	}
	m_brick_active_left = m_count_of_brick;

	m_bar = new Bar();
	m_bar->Init();

	m_ball = new Ball();
	m_ball->Init();

	return errCode;
}

void Game::Update(float deltaTime)
{
	if(!m_is_game_over)
	{
		for(int i = 0; i < m_count_of_brick; i++)
		{
			if(m_brick[i]->IsAlive())
			{
				bool collide_with_brick = m_ball->CheckCollisionWithObject(m_brick[i]->GetRect(), 0);

				if(collide_with_brick)
				{
					m_brick[i]->DeActivate();
					m_brick_active_left--;
				}
			}
		}

		for(int i = 0; i < m_count_of_brick; i++)
		{
			if(m_brick[i]->IsAlive())
				m_brick[i]->Update();
		}

		if(m_brick_active_left == 0)
			m_is_game_over = true;

		if(getKeyState(KeyCode::KEY_LEFT) == KeyState::KEY_PRESSED)
			m_bar->KeyPress(KeyCode::KEY_LEFT);
		else if(getKeyState(KeyCode::KEY_RIGHT) == KeyState::KEY_PRESSED)
			m_bar->KeyPress(KeyCode::KEY_RIGHT);
		else
			m_bar->KeyPress(KeyCode::KEY_UNKNOWN);

		bool collide_with_bar = m_ball->CheckCollisionWithObject(m_bar->GetRect(), m_bar->GetVelocity());

		if(!collide_with_bar)
			m_bar->Update();

		m_ball->Update();

		if(IsExit())
			Exit();

		//Framerate Limited
		if(1000.0f / FRAMERATE > deltaTime)
		{
			Sleep(1000.0f / FRAMERATE - deltaTime);
		}
	}
	else if(getKeyState(KeyCode::KEY_ENTER))
		Reset();
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();

	if(!m_is_game_over)
	{
		g->drawImage(m_background, 0, 0);

		for(int i = 0; i < 45; i++)
		{
			if(m_brick[i]->IsAlive())
				m_brick[i]->Render(g);
		}

		m_bar->Render(g);
		m_ball->Render(g);
	}
	else
	{
		g->drawImage(m_game_over, 0, 0);
	}
}

void Game::Exit()
{
	m_background->unloadImage();
	delete m_background;

	m_game_over->unloadImage();
	delete m_game_over;

	m_ball->Release();
	delete m_ball;

	m_bar->Release();
	delete m_bar;

	for(int i = 0; i < 45; i++)
	{
		m_brick[i]->Release();
		delete m_brick[i];
	}
	delete m_brick;

	exit(1);
}

/////////////////////////////////////
//Support Function
/////////////////////////////////////
bool Game::IsExit()
{
	return getKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEY_PRESSED;
}

void Game::Reset()
{
	for(int i = 0; i < 45; i++)
	{
		m_brick[i]->Activate();
	}
	m_brick_active_left = m_count_of_brick;

	m_bar->Init();
	m_ball->Init();

	m_is_game_over = false;
}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	srand(unsigned(time(NULL)));

	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Rye's Game");

	g.Run();
}