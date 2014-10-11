#pragma once
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#include "stdio_fw.h"
#include "Core\Application.h"

class Sprite
{
protected:
	int Left, Right, Top, Bottom;

	bool IsDraw;
	int veclocity;
public:
	Sprite(int Left = 0, int Right = 0, int Top = 0, int Bottom = 0);
	void DiChuyen();
	bool IsPact(Sprite sprite);
	~Sprite();
};

