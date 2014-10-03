#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"

#include "Game.h"
#include <time.h>
#include <Windows.h>

#define SRCWidth 800
#define SRCHeight 600
#define SqrWidth 50
#define RectWidth 200
#define  RectHeight 30
Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);
	m_SqrSpeedX = 2;
	m_SqrSpeedY = 2;
	m_RectSpeedX = 10;
	m_SqrX = 0;
	m_SqrY = 0;
	m_RectX = 0;
	m_RectY = 400;
	m_SqrColor = 0x00FF00FF;
	return errCode;
}
void Game::LimitFPS(int LimitFPS, float DeltaTime)
{
	int LimitFDT;
	LimitFDT = 1000 / LimitFPS;
	if ( DeltaTime < LimitFDT)
	{
		Sleep(LimitFDT - DeltaTime);
	}
}

unsigned int Game::ColorRandom(int Red, int Green, int Blue, int Alpha)
{
	return ((Red << 24) | (Green << 16) | (Blue << 8) | Alpha);
}

void Game::Update(float deltaTime)
{
	LimitFPS(60, deltaTime);

	//Square conllide with Screen
	m_SqrX += m_SqrSpeedX;
	m_SqrY += m_SqrSpeedY;

	if (m_SqrX >= SRCWidth - SqrWidth) 
	{
		m_SqrX = SRCWidth - SqrWidth;
		m_SqrSpeedX = -m_SqrSpeedX;
	}
	else if (m_SqrX <= 0)
	{
		m_SqrX = 0;
		m_SqrSpeedX = -m_SqrSpeedX;
	}
	if (m_SqrY >= SRCHeight - SqrWidth) 
	{
		m_SqrY = SRCHeight - SqrWidth;
		m_SqrSpeedY = -m_SqrSpeedY;
	} 
	else if (m_SqrY <= 0)
	{
		m_SqrY = 0;
		m_SqrSpeedY = -m_SqrSpeedY;
	}
	//Square conllide with Rect
	if ((m_SqrX + SqrWidth >= m_RectX) && (m_SqrX <= m_RectX + RectWidth))
	{
		if ((m_SqrY + SqrWidth > m_RectY) && (m_SqrY + SqrWidth <= m_RectY + RectHeight))
		{
			m_SqrY = m_RectY - SqrWidth;
		}
		else if ((m_SqrY < m_RectY + RectHeight) && (m_SqrY >= m_RectY))
		{
			m_SqrY = m_RectY + RectHeight;
		}
		if ((m_SqrY + SqrWidth == m_RectY) || (m_SqrY == m_RectY + RectHeight))
		{
			m_SqrSpeedY = -m_SqrSpeedY;
		}
	}
	

	if ((m_SqrY + SqrWidth >= m_RectY) && (m_SqrY <= m_RectY + RectHeight))
	{
		if ((m_SqrX + SqrWidth > m_RectX) && (m_SqrX <= m_RectX ))
		{
			m_SqrX = m_RectX - SqrWidth;
		}
		else if ((m_SqrX < m_RectX + RectWidth) && (m_SqrX > m_RectX + RectWidth - SqrWidth))
		{
			m_SqrX = m_RectX + RectWidth;
		}
		if ((m_SqrX + SqrWidth == m_RectX) || (m_SqrX == m_RectX + RectWidth))
		{
			m_SqrSpeedX = -m_SqrSpeedX;
		}
	}
	
	//Press Key
	if ((m_RectX <SRCHeight) && (GetAsyncKeyState(VK_RIGHT)))
	{
		m_RectX += m_RectSpeedX;
		if (m_RectSpeedX < 0)
		{
			m_RectSpeedX = -m_RectSpeedX;
		}
	}
	else if (m_RectX > 0 && GetAsyncKeyState(VK_LEFT))
	{
		m_RectX += m_RectSpeedX;
		if (m_RectSpeedX > 0)
		{
			m_RectSpeedX = -m_RectSpeedX;
		}
	}
	//Game Over
	if (m_SqrY +SqrWidth >= SRCHeight)
	{
		int Red = rand() % 256;
		int Green = rand() % 256;
		int Blue = rand() % 256;
		m_SqrColor = ColorRandom(Red, Green, Blue, 0);
	}
}

void Game::Render(Graphics* g/*, Block* b, RectControl* r*/)
{
	g->cleanScreen();
	/*b->InitBlock();
	b->RenderBlock(g);
	r->InitRectControl();
	r->RenderRectControl(g);*/
	g->setColor(m_SqrColor);
	g->fillRect(m_SqrX, m_SqrY, SqrWidth, SqrWidth);
	g->setColor(0xFF0000FF);
	g->drawRect(m_SqrX, m_SqrY, SqrWidth, SqrWidth);
	g->fillRect(m_RectX, m_RectY, RectWidth, RectHeight);
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
	
	g.Init(SRCWidth, SRCHeight, "Game");
	g.Run();

	
}