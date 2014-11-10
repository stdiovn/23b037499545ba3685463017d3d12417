#include "stdafx.h"

#include "EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	if(m_instance)
		SAFE_DEL(m_instance);
}

EntityManager* EntityManager::m_instance = 0;

EntityManager* EntityManager::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new EntityManager();
		m_instance->m_entity_list = new EntityList();
	}

	return m_instance;
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
		
	}
}