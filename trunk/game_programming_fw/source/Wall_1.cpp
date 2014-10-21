#include "stdafx.h"
#include"Wall_1.h"

Wall_1::Wall_1()
{
	m_Healthy = 1;
	
	Entity *temp = new Entity();
	temp->activeRenderComponent(ImageWall);

	entities.push_back(temp);
}

Wall_1::~Wall_1()
{
	for (int i = 0; i < entities.size(); i++)
		entities[i]->ClearAll();
}

void Wall_1::setPosition(int x, int y)
{
	for (int i = 0; i < entities.size(); i++)
		entities[i]->setPosition(x, y);
}

void Wall_1::Clear()
{
	Wall_1::~Wall_1();
}

void Wall_1::Render(Graphics *g)
{
	entities[m_Healthy - 1]->Render(g);
}

void Wall_1::de_activeRender()
{
	if (m_Healthy - 1 == 0)
		entities[m_Healthy -1]->deActiveRender();
	else
	{
		m_Healthy--;
	}
}

bool Wall_1::isActiveRender()
{
	return entities[m_Healthy -1]->isActiveRender();
}

int Wall_1::getHeight()
{
	return entities[entities.size() - 1]->getHeight();
}

int Wall_1::getWidth()
{
	return entities[entities.size() - 1]->getWidth();
}