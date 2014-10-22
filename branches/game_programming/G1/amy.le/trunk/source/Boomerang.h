#pragma once
#include "Rect.h"
#include "STDIO_FW\Video\Image.h"
class Boomerang
{
private:
	Rect* m_Rect;
	Image* m_Image;
public:
	Boomerang();
	void Init();
	Rect* GetRect();
	Image* GetImage();
	void Tranfer();
	void Collide(Rect* R);
	void Release();
	~Boomerang();
};

