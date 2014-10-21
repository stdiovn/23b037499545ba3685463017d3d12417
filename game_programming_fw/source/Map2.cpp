#include "Map2.h"

Map2::Map2()
{

}
void Map2::InitMap(char *FileMap)
{
	MapObject::InitMap(FileMap);

	for (int i = 0; i < FramePosition.size(); i++)
	{
		if (FramePosition[i].Index == KindOfWall::WallOneHit)
		{
			FrameWall.push_back(new Wall_1());
			FrameWall[FrameWall.size() - 1]->setPosition(FramePosition[i].X, FramePosition[i].Y);
		}
		else if (FramePosition[i].Index == KindOfWall::WallTwoHit)
		{
			FrameWall.push_back(new Wall_2());
			FrameWall[FrameWall.size() - 1]->setPosition(FramePosition[i].X, FramePosition[i].Y);
		}
	}

	m_BackGround = new Entity();
	m_BackGround->activeRenderComponent(BackGround);
}

Map2::~Map2()
{
}

void Map2::Clear()
{
	MapObject::Clear();
}