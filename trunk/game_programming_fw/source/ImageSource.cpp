#include "stdafx.h"
#include "ImageSource.h"


#define Wall1 "data//wall-break.png"
#define Wall2 "data//wall.png"
#define MapBackGround1 "data//Map_1.jpg"
#define MapBackGround2 "data//Map_2.jpg"
#define ImageMove "data//ThanhMove.png"
#define ImageBall "data//ball.png"


ImageSource* ImageSource::m_Instance = 0;

ImageSource::ImageSource()
{
	m_WallOneHit = new Image(Wall1);
	m_WallTwoHit = new Image(Wall2);
	m_BackGroundMap_1 = new Image(MapBackGround1);
	m_BackGroundMap_2 = new Image(MapBackGround2);
	m_ThanhMove = new Image(ImageMove);
	m_Ball = new Image(ImageBall);
}

void ImageSource::LoadImageSource()
{
	m_WallOneHit->loadImage();
	m_WallTwoHit->loadImage();
	m_BackGroundMap_1->loadImage();
	m_BackGroundMap_2->loadImage();
	m_ThanhMove->loadImage();
	m_Ball->loadImage();
}

ImageSource* ImageSource::GetInstance()
{
	if (m_Instance == 0)
	{
		m_Instance = new ImageSource();
	}

	return m_Instance;
}

Image* ImageSource::GetImage(KindOfImage temp)
{
	switch (temp)
	{
	case KindOfImage::WallOneHit:
		return m_WallOneHit;
	case KindOfImage::WallTwoHit:
		return m_WallTwoHit;
	case KindOfImage::Map_1:
		return m_BackGroundMap_1;
	case KindOfImage::Map_2:
		return m_BackGroundMap_2;
	case KindOfImage::Thanh:
		return m_ThanhMove;
	case KindOfImage::PinkBall:
		return m_Ball;
	}
}

ImageSource::~ImageSource()
{
	delete m_BackGroundMap_1;
	delete m_BackGroundMap_2;
	delete m_Ball;
	delete m_ThanhMove;
	delete m_WallOneHit;
	delete m_WallTwoHit;
}