#include "Global.h"
#include "Rect.h"

DIR Rect::Orientation(Rect temp)
{
	int centerx = (temp.m_Right + temp.m_Left) / 2;
	int centery = (temp.m_Top + temp.m_Bottom) / 2;

	if (centerx < m_Left) return DIR::LEFT;

	if (centerx > m_Right) return DIR::RIGHT;

	if (centery < m_Top) return DIR::ABOVE;

	if (centery > m_Bottom) return DIR::BELOW;

	//return DIR::NONE;
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