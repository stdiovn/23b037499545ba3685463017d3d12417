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

void TransformSystem::Transformation()
{
	std::list<Entity*>::iterator entity = EntityManager::GetInstance()->GetEntityList()->begin();
	while(entity != EntityManager::GetInstance()->GetEntityList()->end())
	{
		if(entity._Ptr->_Myval->GetComponent(ComponentType::COM_TRANSFORM))
		{
			Transform* transform = dynamic_cast<Transform*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_TRANSFORM));
			Movement* move = dynamic_cast<Movement*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_MOVEMENT));

			if(move->m_type == MoveType::MOVE_NORMAL)
			{
				move->m_veloc += move->m_accel;
				//transform->m_position += move->m_veloc;
			}
		}

		entity++;
	}
}