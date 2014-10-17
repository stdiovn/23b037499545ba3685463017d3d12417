#include "ImageSource.h"
#define Wall1 "wall-break.png"
#define Wall2 "wall.png"

ImageSource* ImageSource::m_Instance = 0;

ImageSource::ImageSource()
{
	m_WallOneHit = new Image(Wall1);
	m_WallTwoHit = new Image(Wall2);
}

ImageSource* ImageSource::GetInstance()
{
	if (m_Instance == 0)
	{
		m_Instance = new ImageSource();
	}

	return m_Instance;
}

Image* ImageSource::GetImage(KindOfWall temp)
{
	switch (temp)
	{
	case KindOfWall::WallOneHit:
		return m_WallOneHit;
	case KindOfWall::WallTwoHit:
		return m_WallTwoHit;
	}
}