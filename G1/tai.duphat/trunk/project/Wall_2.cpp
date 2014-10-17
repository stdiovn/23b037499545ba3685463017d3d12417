#include "Wall_2.h"


Wall_2::Wall_2(int width, int height) : Wall_1(width, height)
{
	m_CountImage = 2;
	temp = KindOfWall::WallTwoHit;
}


Wall_2::~Wall_2()
{
}
