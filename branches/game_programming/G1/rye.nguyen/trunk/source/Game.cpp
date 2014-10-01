#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"

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

	//Initialize Object
	m_object.x = 0;
	m_object.y = 0;
	m_object.width = 50;
	m_object.height = 50;

	m_object_color = 0xF000FFFF;

	//Initialize Bar
	m_bar.x = 300;
	m_bar.y = 500;
	m_bar.width = 200;
	m_bar.height = 30;

	m_bar_color = 0x00FFFFFF;

	//Set the Velocity
	m_velocity.x = 3;
	m_velocity.y = 3;

	m_bar_velocity = 5;

	return errCode;
}

void Game::Update(float deltaTime)
{
	m_object.x += m_velocity.x;
	m_object.y += m_velocity.y;

	//Check collides with Screen edges
	if(m_object.x <= 0)
	{
		m_object.x = 0;
		m_velocity.x = -m_velocity.x;
	}
	else if(m_object.x + m_object.width >= SCREEN_WIDTH)
	{
		m_object.x = SCREEN_WIDTH - m_object.width;
		m_velocity.x = -m_velocity.x;
	}
	else if(m_object.y <= 0)
	{
		m_object.y = 0;
		m_velocity.y = -m_velocity.y;
	}
	else if(m_object.y + m_object.height >= SCREEN_HEIGHT)		//Change color when collides with Screen bottom edge
	{
		m_object.y = SCREEN_HEIGHT - m_object.height;
		m_velocity.y = -m_velocity.y;

		m_object_color = RANDOM_RED | RANDOM_GREEN | RANDOM_BLUE | ALPHA;
	}

	//Collision with Bar detected
	if((m_object.x + m_object.width >= m_bar.x && m_object.x <= m_bar.x + m_bar.width && m_object.y + m_object.height >= m_bar.y && m_object.y <= m_bar.y + m_bar.height))
	{
		if(IsCollidedLeft() || IsCollidedRight())
			m_velocity.x = -m_velocity.x;
		if(IsCollidedTop() || IsCollidedBottom())
			m_velocity.y = -m_velocity.y;
	}
	else	//Move bar when not collided with Object	
	{
		if(IsKeyLeft() && m_bar.x > 0)
			m_bar.x -= m_bar_velocity;
		else if(IsKeyRight() && m_bar.x + m_bar.width < SCREEN_WIDTH)
			m_bar.x += m_bar_velocity;
	}

	if(IsExit())
	{
		exit(1);
	}

	//Framerate Limited
	if(1000 / FRAMERATE > deltaTime)
	{
		Sleep(1000 / FRAMERATE - deltaTime);
	}
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();

	//Draw Object
	g->setColor(m_object_color);
	g->drawRect(m_object.x, m_object.y, m_object.width, m_object.height);
	g->fillRect(m_object.x, m_object.y, m_object.width, m_object.height);

	//Draw Bar
	g->setColor(m_bar_color);
	g->drawRect(m_bar.x, m_bar.y, m_bar.width, m_bar.height);
	g->fillRect(m_bar.x, m_bar.y, m_bar.width, m_bar.height);
}

void Game::Exit()
{

}

/////////////////////////////////////
//Support Function
/////////////////////////////////////
bool Game::IsCollidedLeft()
{
	return m_object.x + m_object.width - m_velocity.x < m_bar.x && m_object.x + m_object.width >= m_bar.x 
										&& m_object.y + m_object.height > m_bar.y && m_object.y < m_bar.y + m_bar.height;
}

bool Game::IsCollidedRight()
{
	return m_object.x - m_velocity.x > m_bar.x + m_bar.width && m_object.x <= m_bar.x + m_bar.width
										&& m_object.y + m_object.height > m_bar.y && m_object.y < m_bar.y + m_bar.height;
}

bool Game::IsCollidedTop()
{
	return m_object.y + m_object.height - m_velocity.y < m_bar.y && m_object.y + m_object.height >= m_bar.y
										&& m_object.x + m_object.width > m_bar.x && m_object.x < m_bar.x + m_bar.width;
}

bool Game::IsCollidedBottom()
{
	return m_object.y - m_velocity.y > m_bar.y + m_bar.height && m_object.y <= m_bar.y + m_bar.height
										&& m_object.x + m_object.width > m_bar.x && m_object.x < m_bar.x + m_bar.width;
}

bool Game::IsKeyLeft()
{
	return GetAsyncKeyState(VK_LEFT);
}

bool Game::IsKeyRight()
{
	return GetAsyncKeyState(VK_RIGHT);
}

bool Game::IsExit()
{
	return GetAsyncKeyState(VK_ESCAPE);
}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	srand(time(NULL));

	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Rye's Game");

	g.Run();
}