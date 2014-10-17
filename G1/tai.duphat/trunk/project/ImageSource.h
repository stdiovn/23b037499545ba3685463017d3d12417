#pragma once
#include "STDIO_FW\Video\Image.h"
#include "Global.h"
using namespace stdio_fw;

class ImageSource
{
	Image *m_WallOneHit;
	Image *m_WallTwoHit;

	ImageSource();

	static ImageSource *m_Instance;
public:
	static ImageSource* GetInstance();
	Image* GetImage(KindOfWall);
	~ImageSource();
};

