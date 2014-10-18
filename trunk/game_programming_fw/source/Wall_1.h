#pragma once
#include "Rect.h"
#include <vector>
#include "STDIO_FW\Video\Image.h"
#include "ImageSource.h"
using namespace stdio_fw;

// one hit will be break
class Wall_1
{
protected:
	Image* m_Image;

	int m_CountImage;

	int m_Width, m_Height;
	KindOfImage temp;
public:
	Wall_1(int width = 0, int height = 0);
	void UpdateImage();
	Image *GetImage();
	bool GetActionDraw();
	int GetWidth();
	int GetHeight();
	virtual ~Wall_1();
};

