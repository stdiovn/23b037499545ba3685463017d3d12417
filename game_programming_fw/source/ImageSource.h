#pragma once
#include "STDIO_FW\Video\Image.h"
#include "Global.h"
using namespace stdio_fw;

class ImageSource
{
	Image *m_WallOneHit;
	Image *m_WallTwoHit;
	Image *m_BackGroundMap_1;
	Image *m_BackGroundMap_2;

	Image *m_Ball;
	Image *m_ThanhMove;
	ImageSource();

	static ImageSource *m_Instance;
public:
	static ImageSource* GetInstance();
	void LoadImageSource();
	Image* GetImage(KindOfImage);
	~ImageSource();
};

