#include "stdafx.h"
#include "EntityManager.h"


EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::Init()
{
}

void EntityManager::AddEntity(Entity* E)
{
	m_EntityList.push_back(E);
}
void EntityManager::Release()
{
	while (!m_EntityList.empty())
	{
		m_EntityList.pop_back();
	}

}
	

EntityManager* EntityManager::m_Instance = 0;

EntityManager* EntityManager::GetInstance()
{
	if (!m_Instance)
	{
		m_Instance = new EntityManager();
	}
	return m_Instance;
}

std::list <Entity*>& EntityManager::GetEntityList()
{
	return m_EntityList;
}

void EntityManager::Update()
{
}

void EntityManager::Render(Graphics* G)
{
}