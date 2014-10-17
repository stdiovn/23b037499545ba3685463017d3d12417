#include "BackGround.h"
#define Map_1 "Map_1.txt"

BackGround::BackGround()
{
	m_Wall = new Wall_1(32, 32);
	m_Wall2 = new Wall_2(32, 32);

	ofstream myfile;
	myfile.open(Map_1);

	if (!myfile.is_open()) exit(1);

	int index;
	int x, y;
	while (!myfile.eof())
	{
		myfile << index << x << y;

		ObjectMap m(index, x, y);
		m_FrameOnject.push_back(m);
	}

	m_Size = m_FrameOnject.size();
	myfile.close();
}

Image* BackGround::GetImage(int index)
{
	if (m_FrameOnject[index].Index == 0)
	{
		return m_Wall->GetImage();
	}
	else
	{
		return m_Wall2->GetImage();
	}
}

bool BackGround::IsCollision(Rect ball)
{
	Rect wall;

	int temp;
	for (int i = 0; i < m_Size; i++)
	{
		wall.m_Left = m_FrameOnject[i].X;
		wall.m_Top = m_FrameOnject[i].Y;

		if (m_FrameOnject[i].Index == KindOfWall::WallOneHit)
		{
			wall.m_Right = wall.m_Left + m_Wall->GetWidth();
			wall.m_Bottom = wall.m_Top + m_Wall->GetHeight();
		}
		else
		{
			wall.m_Right = wall.m_Left + m_Wall2->GetWidth();
			wall.m_Bottom = wall.m_Top + m_Wall2->GetHeight();
		}

		if (ball.IsCollisionWithRect(wall))
		{

		}
	}
}
BackGround::~BackGround()
{
}
