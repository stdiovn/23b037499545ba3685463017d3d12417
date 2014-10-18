#pragma once
#include "ImageSource.h"
#include "STDIO_FW\Video\Image.h"
#include "Rect.h"
#include "Ball.h"
using namespace stdio_fw;

class ThanhMove: public Rect
{
	Image *m_Move;
	int m_Speed;
public:
	void Update(KeyCode);
	Image *GetImage();
	ThanhMove();
	~ThanhMove();
};

