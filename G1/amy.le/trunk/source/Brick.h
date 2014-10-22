#pragma once

#include "Rect.h"
#include "STDIO_FW\Video\Image.h"
class Brick
{
private:
	int m_IsAlive;
	Rect* m_Rect;
	Image* m_Image1;
	Image* m_Image2;
	Image* m_Image3;
	int m_Counti;
	int m_Countj;
public:
	Brick();
	void Init();
	Rect* GetRect();
	Image* GetImage();
	void SetCounti(int i);
	void SetCountj(int j);
	void Conllide(Rect* R);
	int GetIsAlive();
	void SetIsAlive(int IsAlive);
	void Release();
	~Brick();
};

