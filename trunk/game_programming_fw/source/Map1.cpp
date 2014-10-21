#include "stdafx.h"
#include"Map1.h"

Map1::Map1()
{
}

void Map1::InitMap(char *FileMap)
{
	MapObject::InitMap(FileMap);

	for (int i = 0; i < FramePosition.size(); i++)
	{
		if (FramePosition[i].Index == KindOfWall::WallOneHit)
		{
			FrameWall.push_back(new Wall_1());
			FrameWall[FrameWall.size() - 1]->setPosition(FramePosition[i].X, FramePosition[i].Y);
		}
		else
		{
			FrameWall.push_back(new Wall_2());
			FrameWall[FrameWall.size() - 1]->setPosition(FramePosition[i].X, FramePosition[i].Y);
		}
	}

	m_BackGround = new Entity();
	m_BackGround->activeRenderComponent(BackGround);
}

bool Map1::NextMap()
{
	return MapObject::NextMap();
}