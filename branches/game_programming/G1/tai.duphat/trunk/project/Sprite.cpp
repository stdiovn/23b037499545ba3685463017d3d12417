#include "Sprite.h"

Rect::Rect(int left, int right, int top, int bottom, std::pair<int, int> veclocity)
{
	m_Left = left;
	m_Right = right;
	m_Top = top;
	m_Bottom = bottom;

	IsDraw = true;
	IsPactWithWindows = false;
	this->veclocity.first = veclocity.first;
	this->veclocity.second = veclocity.second;
}

void Rect::KeyBoard(KeyCode key)
{
	if (key == KeyCode::KEY_LEFT)
	{
		m_Left -= veclocity.first;
		m_Right -= veclocity.first;
	}
	else if (key == KeyCode::KEY_RIGHT)
	{
		m_Left += veclocity.first;
		m_Right += veclocity.first;
	}
}

bool Rect::IsPact(Rect sprite)
{
	// va cham voi 4 canh cua so
	if (!IsPactWithWindows)
	{
		if ((m_Left < 0 || m_Right > SCREEN_WIDTH))
		{
			veclocity.first = -veclocity.first;
			IsPactWithWindows = true;
		}
		else if ((m_Top < 0 || m_Bottom > SCREEN_HEIGHT))
		{
			veclocity.second = -veclocity.second;
			IsPactWithWindows = true;
		}
	}
	// va cham voi object

	int TamI1_X = (m_Left + m_Right) / 2;
	int TamI1_Y = (m_Top + m_Bottom) / 2;

	int TamI2_X = (sprite.m_Left + sprite.m_Right) / 2;
	int TamI2_Y = (sprite.m_Bottom + sprite.m_Top) / 2;

	if ((abs(TamI1_X - TamI2_X) < (((m_Right - m_Left) + (sprite.m_Right - sprite.m_Left)) / 2)
		&& (abs(TamI2_Y - TamI1_Y) < ((m_Bottom - m_Top) + (sprite.m_Bottom - sprite.m_Top)) / 2)))
	{
		//veclocity.first = -veclocity.first;
		veclocity.second = -veclocity.second;
		return true;
	}

	return false;
}

void Rect::Update()
{
	m_Left += veclocity.first;
	m_Top += veclocity.second;
	m_Right += veclocity.first;
	m_Bottom += veclocity.second;
	IsPactWithWindows = false;
}

Rect::~Rect()
{
}
