#include "stdafx.h"

#include "EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	
}

EntityManager* EntityManager::m_instance = 0;

EntityManager* EntityManager::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new EntityManager();
		m_instance->Init();
	}

	return m_instance;
}

void EntityManager::Init()
{
	m_entity_list = new EntityList();
}

void EntityManager::Release()
{
	ReleaseAllEntity();
	SAFE_DEL(m_entity_list);

	if(m_instance)
		SAFE_DEL(m_instance);
}

EntityList* EntityManager::GetEntityList()
{
	return m_entity_list;
}

void EntityManager::AddEntity(Entity* entity)
{
	m_entity_list->push_back(entity);
}

void EntityManager::ReleaseAllEntity()
{
	while(!m_entity_list->empty())
	{
		m_entity_list->back()->Release();
		SAFE_DEL(m_entity_list->back());
		m_entity_list->pop_back();
	}
}