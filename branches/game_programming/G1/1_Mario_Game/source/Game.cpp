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
	m_mario_rect = Rect(200, 400 - 48, 26, 48);
	m_offset = 0;
	m_default_veloc = 1;
	m_veloc = m_default_veloc;

	m_map = new Image("image//State_1.png");
	m_map->loadImage();

	m_enemy = new Image("image//NES - Super Mario Bros - Enemies.png");
	m_enemy->loadImage();
	m_enemy_rect = new Rect[3];
	m_enemy_src_rect = new Rect[3];

	m_enemy_rect[0] = Rect(570, 400 - 24, 24, 24);
	m_enemy_rect[1] = Rect(2700, 400 - 33, 23, 33);
	m_enemy_rect[2] = Rect(4100, 400 - 48, 48, 48);

	m_enemy_src_rect[0] = Rect(0, 16, 16, 16);
	m_enemy_src_rect[1] = Rect(96, 10, 15, 22);
	m_enemy_src_rect[2] = Rect(656, 0, 32, 32);

	m_enemy_veloc = new int[3]{-2, 1, -1};

	m_state = GameState::STATE_PLAY;

	return errCode;
}

void Game::update(float deltaTime)
{
	if(m_state == GameState::STATE_PLAY)
	{
		//Move left/right
		if(getKeyState(KeyCode::KEY_LEFT) == KeyState::KEY_PRESSED)
		{
			if(m_mario_rect.x > 390 || m_offset <= 0)
				m_mario_rect.x -= m_veloc;
			else
			{
				m_offset -= 2;
				for(int i = 0; i < 3; i++)
				{
					m_enemy_rect[i].x += 2;
				}
			}

			if(m_veloc < 6)
				m_veloc++;
		}
		else if(getKeyState(KeyCode::KEY_RIGHT) == KeyState::KEY_PRESSED)
		{
			if(m_mario_rect.x < 390 || m_offset > 3500)
				m_mario_rect.x += m_veloc;
			else
			{
				m_offset += 2;
				for(int i = 0; i < 3; i++)
				{
					m_enemy_rect[i].x -= 2;
				}
			}

			if(m_veloc < 6)
				m_veloc++;
		}
		else
			if(m_veloc > m_default_veloc)
				m_veloc--;
		////////////////////////////////////////////////////////////////////////



		//Jump
		if(getKeyState(KeyCode::KEY_UP) == KeyState::KEY_PRESSED)
		{
			if(m_mario_rect.y == 400 - 48)
				m_is_jumping = 10;
		}

		if(m_is_jumping > 0)
		{
			m_mario_rect.y -= 12;
			m_is_jumping--;
		}

		if(m_mario_rect.y < 400 - 48)
			m_mario_rect.y += 2;
		////////////////////////////////////////////////////////////////////////



		if(isCollide(m_enemy_rect[0], Rect(0, 0, 1, 200)) || isCollide(m_enemy_rect[0], Rect(448, 168, 32, 32)))
			m_enemy_veloc[0] *= -1;
		if(isCollide(m_enemy_rect[1], Rect(2085, 270, 30, 45)) || isCollide(m_enemy_rect[1], Rect(3276, 276, 24, 24)))
			m_enemy_veloc[0] *= -1;
		if(isCollide(m_enemy_rect[2], Rect(3912, 252, 45, 48)) || isCollide(m_enemy_rect[2], Rect(4296, 276, 45, 48)))
			m_enemy_veloc[0] *= -1;

		for(int i = 0; i < 3; i++)
			m_enemy_rect[i].x += m_enemy_veloc[i];


		//Finish state
		for(int i = 0; i < 3; i++)
		{
			if(isCollide(m_mario_rect, m_enemy_rect[i]))
			{
				m_state = GameState::STATE_GAME_OVER;
				break;
			}
		}
		if(m_offset >= 3010)
			m_state = GameState::STATE_WIN;
		////////////////////////////////////////////////////////////////////////
	}
	//Restart game
	else if(getKeyState(KeyCode::KEY_ENTER) == KeyState::KEY_PRESSED)
	{
		m_mario_rect.x = 200;
		m_offset = 0;
		m_enemy_rect[0] = Rect(570, 400 - 24, 24, 24);
		m_enemy_rect[1] = Rect(2700, 400 - 33, 23, 33);
		m_enemy_rect[2] = Rect(4100, 400 - 48, 48, 48);

		m_state = GameState::STATE_PLAY;
	}
	////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////
	//Coder: Rye
	//Purpose: manage FPS
	if(1000.0f / FPS > deltaTime)
		Sleep(1000.0f / FPS - deltaTime);
}

void Game::render(Graphics* g)
{
	g->cleanScreen();

	g->drawRegion(m_map, Rect(0, 100, 800, 336), Rect(m_offset, 0, 533, 224));

	if(m_state == GameState::STATE_PLAY)
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
	}
}

void Game::exit()
{
	
}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	
}