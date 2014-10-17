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

	bool m_IsDraw;
	bool m_IsColiision;

	int m_Width, m_Height;
	KindOfWall temp;
public:
	Wall_1(int width = 0, int height = 0);
	void UpdateImage();
	Image *GetImage();
	bool GetAction();
	int GetWidth();
	int GetHeight();
	~Wall_1();
};

