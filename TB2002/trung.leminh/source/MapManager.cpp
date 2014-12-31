#include "stdafx.h"
#include "BonusSpeedBallItem.h"
#include "Mapmanager.h"
#include "Geometry.h"

using namespace std;

CMapmanager::CMapmanager()
{
	m_map	= new SMap(L"Map1.txt");
	m_score = 0;
}


CMapmanager::~CMapmanager()
{
	
}



//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Load data
/// @parameter:   No
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapmanager::loadMap()
{

	int		idBrick		= 0,
			posBrickX	= 0,
			posBrickY	= 0,
			rectBrickX	= 0,
			rectBrickY	= 0,
			isCollis	= 0;
	wstring	typeBrick;

	// create local memory	
	
	wfstream fileStream(m_map->m_nameMap);
	if (fileStream.is_open())
	{
		while (!fileStream.eof())
		{
			fileStream >> idBrick >> posBrickX >> posBrickY >> rectBrickX >> rectBrickY >> isCollis >> typeBrick;
			switch (getNameBrick(typeBrick))
			{
			case WOOD_BRICK:
				m_map->m_brick.push_back(new CWood(WOOD_FILE_PATH, s_vector2D(posBrickX, posBrickY)));
				break;
			case STONE_BRICK:
				m_map->m_brick.push_back(new CStone(WOOD_FILE_PATH, STONE_FILE_PATH, s_vector2D(posBrickX, posBrickY)));
				break;
			default:
				break;
			}
			
		}
	}
}

void CMapmanager::Init()
{
	loadMap();
	for (int i = 0; i < m_map->m_brick.size(); i++)
	{
		m_map->m_brick[i]->Init();
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update all object in map with ball. This mean we check collision between ball and object in map
/// @parameter:   float deltaTime, CBall* ball
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapmanager::Update(float deltaTime, CBall* ball)
{
	if (m_map->m_listItem.size() != 0)
	{
		for (int i = 0; i < m_map->m_listItem.size(); i++)
		{
			if (checkIntersectRectangle(m_map->m_listItem[i]->getSizeRectOfObject(), ball->getSizeRectOfObject()))
			{
				if (m_map->m_listItem[i]->getID() == L"BonusSpeed")
				{
					ball->setVelocity(s_vector2D((ball->getVelocity().X) + 5, (ball->getVelocity().Y) + 5));
				}
			}
		}
	}
	// ----------------stupid idea----------------------------//
	for (int i = 0; i < m_map->m_brick.size(); i++)
	{
		if (m_map->m_brick[i])
		{
			m_map->m_brick[i]->Update(deltaTime);
			if (checkIntersectRectangle(m_map->m_brick[i]->getSizeRectOfObject(), ball->getSizeRectOfObject()))
			{
				m_score += 5;
				if (m_map->m_brick[i]->getStateBrick() == e_StateBrick::STONE_BRICK_STATE)
				{
					m_map->m_brick[i]->setStateBrick(WOOD_BRICK_STATE);
				}
				else if (m_map->m_brick[i]->getStateBrick() == e_StateBrick::WOOD_BRICK_STATE)
				{
					//if (RandomInt(11, 10) == 10) // create speed bom....
					//{
					//	m_map->m_listItem.push_back(new CBonusSpeedBallItem(BONUS_SPEED_PATH, m_map->m_brick[i]->getPosition()));
					//}
					m_map->m_listItem.push_back(new CBonusSpeedBallItem(BONUS_SPEED_PATH, m_map->m_brick[i]->getPosition()));
					CBrick* tempBrick = m_map->m_brick[i];
					m_map->m_brick.erase(m_map->m_brick.begin() + i);
					delete tempBrick;
				}
			}
		}
	}

	if (m_map->m_brick.size() <= 0)
	{
		if (m_map->m_nameMap == L"Map1.txt")
		{
			m_map->m_nameMap = L"Map2.txt";
			Init();
		}

	}
}
//------------------------------------------------//
e_KindOfBrick CMapmanager::getNameBrick(wstring name)
{
	if (name == L"0T")
		return WOOD_BRICK;
	if (name == L"1T")
		return STONE_BRICK;

	printf("Don't specific type name brick");
	exit(0);
}
//------------------------------------------------------//
SMap CMapmanager::getMap()
{
	return *m_map;
}
//----------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render all thing in map. We only render brick and stone
/// @parameter:   Graphics* g
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CMapmanager::Render(Graphics* g)
{
	for (int i = 0; i < m_map->m_listItem.size(); i++)
	{
		m_map->m_listItem[i]->Render(g);
	}
	
	for (int i = 0; i < m_map->m_brick.size(); i++)
	{
		m_map->m_brick[i]->Render(g);
	}
	
}

