#include "stdafx.h"

#include "EntityManager.h"
#include "TransformSystem.h"

TransformSystem::TransformSystem()
{

}

TransformSystem::~TransformSystem()
{

}

TransformSystem* TransformSystem::m_instance = 0;

TransformSystem* TransformSystem::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new TransformSystem();
		m_instance->Init();
	}

	return m_instance;
}

void TransformSystem::Init()
{

}

void TransformSystem::Release()
{
	if(m_instance)
		SAFE_DEL(m_instance);
}

void TransformSystem::Transform()
{
	std::list<Entity*>::iterator entity = EntityManager::GetInstance()->GetEntityList()->begin();
	while(entity != EntityManager::GetInstance()->GetEntityList()->end())
	{
		

		entity++;
	}
}