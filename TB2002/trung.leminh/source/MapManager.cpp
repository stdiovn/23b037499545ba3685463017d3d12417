#include "stdafx.h"
#include "Sun.h"
#include "MapManager.h"
#include "Geometry.h"
#include <vector>
	
extern e_StateGame g_statusGame;

CMapManager::CMapManager()
{
}


CMapManager::~CMapManager()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Initialize all thing in map
/// @parameter:   No
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapManager::Init()
{
	int		idCloud,
			posCloudX,
			posCloudY,
			rectCloudX,
			rectCloudY;

	// create local memory	
	m_map = new SMap();
	wfstream fileStream(L"MapOne_Cloud.txt");
	if (fileStream.is_open())
	{
		while (!fileStream.eof())
		{
			fileStream >> idCloud >> posCloudX >> posCloudY >> rectCloudX >> rectCloudY;
			m_map->m_cloud.push_back(new CCloud(posCloudX, posCloudY, 0, 0));
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update all object in map with sun. This mean we check collision between sun and object in map
/// @parameter:   CSun* sun
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapManager::Update(CSun* sun)
{
	// ----------------stupid idea----------------------------//
	for (int i = 0; i < m_map->m_cloud.size(); i++)
	{
		if (checkIntersectRectangle(m_map->m_cloud[i]->getSizeRectOfObject(), sun->getSizeRectOfObject()))
		{
			CCloud* tempCloud = m_map->m_cloud[i];
			(m_map->m_cloud).erase(m_map->m_cloud.begin() + i);
			tempCloud->Release();
		}
	}

	if (m_map->m_cloud.size() <= 0)
	{
		g_statusGame = END_CONGTRATULATION;
	}
}


//--------------------------------------------------------------------------------------------------------------------------------
/// @description: return some information of Map
/// @parameter:   No
/// @return type: SMap.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
SMap CMapManager::getMap()
{
	return *m_map;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render all thing in map. We only render cloud
/// @parameter:   Graphics* g
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapManager::Render(Graphics* g)
{
	for (int i = 0; i < m_map->m_cloud.size(); i++)
	{
		m_map->m_cloud[i]->Render(g);
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Release resource of all thing in map
/// @parameter:   No
/// @return type: void.
/// @warning :	  Alway remember it
//---------------------------------------------------------------------------------------------------------------------------------
void CMapManager::Release()
{
	//delete[] &m_map->m_cloud;
}