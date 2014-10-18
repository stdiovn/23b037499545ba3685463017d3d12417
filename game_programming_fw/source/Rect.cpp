#include "stdafx.h"
#include "Rect.h"

Rect::Rect(int left, int right, int top, int bottom)
{
	m_Left = left;
	m_Right = right;
	m_Top = top;
	m_Bottom = bottom;
}

DIR Rect::Orientation(int _Left, int _Right, int _Top, int _Bottom)
{
	int centerx = (m_Right + m_Left) / 2;
	int centery = (m_Top + m_Bottom) / 2;

	if (centerx < _Left)
	{
		return DIR::LEFT;
	}

	if (centerx > _Right)
	{
		return DIR::RIGHT;
	}

	if (centery < _Top)
	{
		return DIR::ABOVE;
	}

	if (centery > _Bottom)
	{
		return DIR::BELOW;
	}

	//return DIR::NONE;
}

bool Rect::IsCollisionWithRect(int _Left, int _Right, int _Top, int _Bottom)
{
	int TamI1_X = (m_Left + m_Right) / 2;
	int TamI1_Y = (m_Top + m_Bottom) / 2;

	int TamI2_X = (_Left + _Right) / 2;
	int TamI2_Y = (_Bottom + _Top) / 2;

	if ((abs(TamI1_X - TamI2_X) < (((m_Right - m_Left) + (_Right - _Left)) / 2)
		&& (abs(TamI2_Y - TamI1_Y) < ((m_Bottom - m_Top) + (_Bottom - _Top)) / 2)))
	{
		return true;
	}

	return false;
}

Rect::~Rect()
{
}
