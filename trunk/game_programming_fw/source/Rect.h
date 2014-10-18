#pragma once
#include <map>
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\stdio_fw.h"
#include "Global.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace stdio_fw;

class Rect
{
public:
	int m_Left;
	int m_Right;
	int m_Top;
	int m_Bottom;

	Rect(int left = 0, int right = 0, int top = 0, int bottom = 0);

	bool IsCollisionWithRect(int _Left, int _Right, int _Top, int _Bottom);
	DIR Orientation(int _Left, int _Right, int _Top, int _Bottom);
	~Rect();
};

