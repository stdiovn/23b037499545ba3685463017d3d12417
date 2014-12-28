#pragma once

#include "STDIO_FW\Video\Image.h"
#include <list>
#include <vector>
using namespace stdio_fw;

struct Point2D
{
	int x;
	int y;
};

struct RenderComp
{
	Point2D m_Position;
	Image* m_Image;
	int GetX() { return m_Position.x;}
	void SetX(int x) { m_Position.x = x; }
	int GetY() { return m_Position.y; }
	void SetY(int y) { m_Position.y = y;}
};

enum MoveType
{
	Sin = 1,
	Line
};

struct MoveComp
{
	int m_Velocity;
	int m_Angle;
	Point2D m_CurrPoint;
	Point2D m_Centre;
	MoveType m_Type;
	RenderComp m_Render;
	int m_CurrAngle;
};

struct AnimationComp
{
	std::vector <Image*> m_ImageList;
	int					m_currentFrame;
	int					m_counter;
	int					m_FramesPerUpdate;

	AnimationComp()
	{
		m_currentFrame = 0;
		m_counter = 0;
		m_FramesPerUpdate = 3;
	}
};
