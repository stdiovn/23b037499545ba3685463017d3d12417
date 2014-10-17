#pragma once
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#include <map>
#include "stdafx.h"
using namespace stdio_fw;
class Rect
{
	std::pair<int, int> veclocity;
	bool IsPactWithWindows;

public:
	Rect(int left = 0, int right = 0, int top = 0, int bottom = 0, std::pair<int, int> veclocity = std::pair<int,int>(0,0));
	bool IsDraw;
	void KeyBoard(KeyCode);
	bool IsPact(Rect);

	void Update();

	int m_Left;
	int m_Right;
	int m_Top;
	int m_Bottom;

	~Rect();
};

