#pragma once
#include "ImageSource.h"
#include "STDIO_FW\Video\Image.h"
#include "Rect.h"

class Ball : public Rect
{
	Image *m_Ball;

	int m_Veclocity_x;
	int m_Veclocity_y;

	DIR m_DIR;
public:
	Ball();
	Image *GetImage(); 
	void SetDIR(DIR);
	void Update();
};