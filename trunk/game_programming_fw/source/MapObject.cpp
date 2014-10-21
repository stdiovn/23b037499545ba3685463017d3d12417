#include "stdafx.h"
#include "MapObject.h"
#define ImageGameOver "data//GameOver.jpg"

MapObject::MapObject()
{
	m_CountWallOnScreen = 0;
	m_BackGround = NULL;

	m_GameOver = new Entity();
	m_GameOver->activeRenderComponent(ImageGameOver);

	isActive = true;
}

void MapObject::InitMap(char *MapFile)
{
	ifstream myfile;
	myfile.open(MapFile);

	if (!myfile.is_open()) return;

	while (!myfile.eof())
	{
		int index;
		int x, y;

		myfile >> index >> x >> y;
		Object temp(index, x, y);
		FramePosition.push_back(temp);
	}
	myfile.close();

	m_CountWallOnScreen = FramePosition.size();
}

void MapObject::Render(Graphics *g)
{
	if (isActive)
	{
		m_BackGround->Render(g);
		for (int i = 0; i < FrameWall.size(); i++)
		{
			FrameWall[i]->Render(g);
		}
	}
	else
	{
		m_GameOver->Render(g);
	}
}

MapObject::~MapObject()
{
	for (int i = 0; i < FrameWall.size(); i++)
	{
		FrameWall[i]->Clear();
	}

	m_BackGround->ClearAll();
	m_GameOver->ClearAll();
}

void MapObject::Clear()
{
	MapObject::~MapObject();
}

int MapObject::getWidth(int index)
{
	return FrameWall[index]->getWidth();
}

Object MapObject::getPosition(int index)
{
	return FramePosition[index];
}

int MapObject::getHeight(int index)
{
	return FrameWall[index]->getHeight();
}

bool MapObject::NextMap()
{
	m_CountWallOnScreen = 0;
	for (int i = 0; i < FrameWall.size(); i++)
	{
		if (FrameWall[i]->isActiveRender())
			m_CountWallOnScreen++;
	}

	if (m_CountWallOnScreen == 0) return true;

	return false;
}

int MapObject::getCountFrameWallOnMap()
{
	return FrameWall.size();
}

bool MapObject::isActiveRenderAt(int index)
{
	return FrameWall[index]->isActiveRender();
}

void MapObject::deActiveRenderAt(int index)
{
	FrameWall[index]->de_activeRender();
}

bool MapObject::isGameOver()
{
	return !isActive;
}

void MapObject::setIsActive(bool active)
{
	isActive = active;
}