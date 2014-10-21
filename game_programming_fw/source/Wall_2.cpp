#include "stdafx.h"
#include"Wall_2.h"

Wall_2::Wall_2()
{
	m_Healthy = 2;

	entities.push_back(new Entity());
	entities[entities.size() - 1]->activeRenderComponent(ImageWall2);
}

