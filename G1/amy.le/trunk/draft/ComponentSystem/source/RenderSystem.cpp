#include "stdafx.h"
#include "RenderSystem.h"
#include "Support.h"
RenderSystem::RenderSystem()
{
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update()
{

}

void RenderSystem::Render(Graphics* g)
{
	std::list<Entity*> entities = EntityManager::GetInstance()->GetEntityList();
	std::list<Entity*>::iterator CurrEntity = entities.begin();
	while (CurrEntity != entities.end())
	{
		Entity* E = *CurrEntity;
		
		if (E->hasRendererComponent())
		{
			g->drawImage(E->GetRenderComp().m_Image, E->GetRenderComp().m_Position.x, E->GetRenderComp().m_Position.y);
		}
		CurrEntity++;
	}
}

