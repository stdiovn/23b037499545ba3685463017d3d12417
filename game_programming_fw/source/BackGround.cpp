#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{

}
BackGround::BackGround(char *PathOfFileMap)
{
	ifstream myfile;
	myfile.open(PathOfFileMap);

	if (!myfile.is_open()) return;

	int index;
	int x, y;
	while (!myfile.eof())
	{
		myfile >> index >> x >> y;
		ObjectMap m(index, x, y);
		m_FrameOnject.push_back(m);
	}
	myfile.close();


	m_Size = m_FrameOnject.size();
	m_isDraw = new bool[m_Size];
	
	for (int i = 0; i < m_Size; i++)
		m_isDraw[i] = true;

	for (int i = 0; i < m_Size; i++)
	{
		if (m_FrameOnject[i].Index == KindOfImage::WallOneHit)
		{
			m_FrameWall.push_back(new Wall_1());
		}
		else
		{
			m_FrameWall.push_back(new Wall_2());
		}
	}
	m_BackGround = ImageSource::GetInstance()->GetImage(KindOfImage::Map_1);
}

Wall_1* BackGround::GetWall(int index)
{
	return m_FrameWall[index];
}

void BackGround::Update()
{
	for (int i = 0; i < m_FrameOnject.size(); i++)
	{
		m_FrameWall[i]->UpdateImage();
	}

	GetCoutOfWallOnScreen();
}

bool BackGround::NextBackGround()
{
	if (m_Size == 0) return true;

	return false;
}

void BackGround::GetCoutOfWallOnScreen()
{
	m_Size = 0;
	for (int i = 0; i < m_FrameOnject.size(); i++)
	{
		if (m_isDraw[i])
			m_Size++;
	}
}
BackGround::~BackGround()
{
	delete []m_isDraw;

	for (int i = 0; i < m_FrameWall.size(); i++)
		delete m_FrameWall[i];
}
