#pragma once
#include "Rect.h"
#include "STDIO_FW\Video\Image.h"

class Turtle
{
	Rect* m_Rect;
	Image* m_Image;
public:
	Turtle();
	void Init();
	void Collide(Rect* R);
	Rect* GetRect();
	Image* GetImage();
	void Release();
	~Turtle();
};

