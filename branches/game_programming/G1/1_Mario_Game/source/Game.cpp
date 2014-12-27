#include "stdafx.h"

#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::init(screenW, screenH, title);
	
	/////////////////////////////////////////////////
	//Coder: Rye
	//Purpose: Init Mario for rendering
	m_mario = new Image("image//NES - Super Mario Bros - Mario Luigi.png");
	m_mario->loadImage();
	m_mario_rect = Rect(200, 336, 34, 64);
	m_offset = 0;

	m_enemy = new Image("image//NES - Super Mario Bros - Enemies.png");
	m_enemy->loadImage();
	m_enemy_rect = new Rect[3];
	m_enemy_src_rect = new Rect[3];

	m_enemy_rect[0] = Rect(1000, 400 - 32, 32, 32);
	m_enemy_rect[1] = Rect(800, 400 - 44, 30, 44);
	m_enemy_rect[2] = Rect(600, 400 - 64, 64, 64);

	m_enemy_src_rect[0] = Rect(0, 16, 16, 16);
	m_enemy_src_rect[1] = Rect(96, 10, 15, 22);
	m_enemy_src_rect[2] = Rect(656, 0, 32, 32);

	m_count_move = new int[3]{0, 0, 0};

	m_state = GameState::STATE_PLAY;

	return errCode;
}

void Game::update(float deltaTime)
{
	if(m_state == GameState::STATE_PLAY)
	{
		if(getKeyState(KeyCode::KEY_LEFT) == KeyState::KEY_PRESSED)
		{
			if(m_mario_rect.x > 390 || m_offset <= 0)
				m_mario_rect.x -= 3;
			else
			{
				m_offset -= 2;
				for(int i = 0; i < 3; i++)
				{
					m_enemy_rect[i].x += 2;
				}
			}
		}
		else if(getKeyState(KeyCode::KEY_RIGHT) == KeyState::KEY_PRESSED)
		{
			if(m_mario_rect.x < 390 || m_offset > 3500)
				m_mario_rect.x += 3;
			else
			{
				m_offset += 2;
				for(int i = 0; i < 3; i++)
				{
					m_enemy_rect[i].x -= 2;
				}
			}
		}

		for(int i = 0; i < 3; i++)
		{
			m_count_move[i]++;
			if(m_count_move[i] > 300)
				m_count_move -= 600;

			if(m_count_move[i] > 0)
				m_enemy_rect[i].x -= 1;
			else
				m_enemy_rect[i].x += 1;
		}

		for(int i = 0; i < 3; i++)
		{
			if(isCollide(m_mario_rect, m_enemy_rect[i]))
			{
				m_state = GameState::STATE_GAME_OVER;
				break;
			}
		}
		if(m_mario_rect.x >= 3000)
			m_state = GameState::STATE_WIN;
	}
	else if(getKeyState(KeyCode::KEY_ENTER) == KeyState::KEY_PRESSED)
	{
		m_mario_rect.x = 200;
		m_enemy_rect[0] = Rect(1000, 400 - 32, 32, 32);
		m_enemy_rect[1] = Rect(800, 400 - 44, 30, 44);
		m_enemy_rect[2] = Rect(600, 400 - 64, 64, 64);

		m_state = GameState::STATE_PLAY;
	}

	/////////////////////////////////////////////////
	//Coder: Rye
	//Purpose: manage FPS
	if(1000.0f / FPS > deltaTime)
		Sleep(1000.0f / FPS - deltaTime);
}

void Game::render(Graphics* g)
{
	g->cleanScreen();

	/*if(m_state == GameState::STATE_PLAY)
	{
		g->drawRegion(m_mario, m_mario_rect.x, m_mario_rect.y, m_mario_rect.width, m_mario_rect.height, 80, 0, 17, 32);
		for(int i = 0; i < 3; i++)
		{
			g->drawRegion(m_enemy, m_enemy_rect[i], m_enemy_src_rect[i]);
		}
	}
	else if(m_state == GameState::STATE_WIN)
	{
		g->setColor(0x00FF00FF);
		g->drawText("You win!!!", 300, 300, 5, 5);
	}
	else if(m_state == GameState::STATE_GAME_OVER)
	{
		g->setColor(0xFF0000FF);
		g->drawText("Game over!!!", 0, 0, 5, 5);
	}*/

	g->setColor(0xFF0000FF);
	g->drawText("STDIO", 20, 20);
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}