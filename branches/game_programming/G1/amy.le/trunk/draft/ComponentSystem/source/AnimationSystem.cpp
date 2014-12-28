#include "stdafx.h"
#include "AnimationSystem.h"
#include "Support.h"

#define AnimationX 100
#define AnimationY 100
AnimationSystem::AnimationSystem()
{
}

AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::Update()
{
	std::list<Entity*> entities = EntityManager::GetInstance()->GetEntityList();
	std::list<Entity*>::iterator CurrEntity = entities.begin();
	while (CurrEntity != entities.end())
	{
		Entity* E = *CurrEntity;
		if (E->hasAnimationComponent())
		{
			AnimationComp& comp = E->GetAnimationComp();

			comp.m_counter++;
			if (comp.m_counter >= comp.m_FramesPerUpdate)
			{
				comp.m_currentFrame = (comp.m_currentFrame + 1) % comp.m_ImageList.size();
				comp.m_counter = 0;
			}
		}
		CurrEntity++;
	}
}

void AnimationSystem::Render(Graphics* G)
{
	std::list<Entity*> entities = EntityManager::GetInstance()->GetEntityList();
	std::list<Entity*>::iterator CurrEntity = entities.begin();
	while (CurrEntity != entities.end())
	{
		Entity* E = *CurrEntity;
		if (E->hasAnimationComponent())
		{
			AnimationComp& comp = E->GetAnimationComp();

			G->drawImage(comp.m_ImageList[comp.m_currentFrame], AnimationX, AnimationY);

		}
		CurrEntity++;
	}
}

