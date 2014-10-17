#include "Rect.h"


Rect::Rect(int left, int right, int top, int bottom)
{
	m_Left = left;
	m_Right = right;
	m_Top = top;
	m_Bottom = bottom;
}

bool Rect::IsCollisionWithRect(Rect x)
{
	int TamI1_X = (m_Left + m_Right) / 2;
	int TamI1_Y = (m_Top + m_Bottom) / 2;

	int TamI2_X = (x.m_Left + x.m_Right) / 2;
	int TamI2_Y = (x.m_Bottom + x.m_Top) / 2;

	if ((abs(TamI1_X - TamI2_X) < (((m_Right - m_Left) + (x.m_Right - x.m_Left)) / 2)
		&& (abs(TamI2_Y - TamI1_Y) < ((m_Bottom - m_Top) + (x.m_Bottom - x.m_Top)) / 2)))
	{
		return true;
	}

	return false;
}

Rect::~Rect()
{
}
