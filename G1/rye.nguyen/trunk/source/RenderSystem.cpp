#include "stdafx.h"

#include "EntityManager.h"
#include "RenderSystem.h"

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{
	
}

RenderSystem* RenderSystem::m_instance = 0;

RenderSystem* RenderSystem::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new RenderSystem();
		m_instance->Init();
	}

	return m_instance;
}

void RenderSystem::Init()
{

}

void RenderSystem::Release()
{
	if(m_instance)
		SAFE_DEL(m_instance);
}

void RenderSystem::Render(Graphics* g)
{
	std::list<Entity*>::iterator entity = EntityManager::GetInstance()->GetEntityList()->begin();
	while(entity != EntityManager::GetInstance()->GetEntityList()->end())
	{
		Renderer* render = dynamic_cast<Renderer*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_RENDERER));
		if(render)
		{
			Transform* transform = dynamic_cast <Transform*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_TRANSFORM));
			g->drawImage(render->m_image, transform->m_position->x, transform->m_position->y);
		}

		entity++;
	}
}