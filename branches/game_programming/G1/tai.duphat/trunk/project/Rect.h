#pragma once
#include <map>
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\stdio_fw.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace stdio_fw;

class Rect
{

public:
	int m_Left;
	int m_Right;
	int m_Top;
	int m_Bottom;

	Rect(int left = 0, int right = 0, int top = 0, int bottom = 0);
	bool GetCollision();
	bool IsCollisionWithRect(Rect);
	~Rect();
};

