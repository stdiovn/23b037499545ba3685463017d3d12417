#include "stdafx.h"
#include "MovementSystem.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Support.h"
MovementSystem::MovementSystem()
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::Update()
{
	std::list<Entity*> entities = EntityManager::GetInstance()->GetEntityList();
	std::list<Entity*>::iterator CurrEntity = entities.begin();

	while (CurrEntity != entities.end())
	{

		Entity* E = *CurrEntity;
		if (E->hasMovementComponent())
		{
			MoveComp& MComp = E->GetMoveComp();
			RenderComp& RComp = E->GetRenderComp();
			if (MComp.m_Type == 1)
			{
				RComp.SetX(RComp.GetX() + MComp.m_Velocity);
				RComp.SetY(60 * sin(RComp.GetX() * M_PI / 180));
			}
			else if (MComp.m_Type == 2)
			{
				RComp.SetX(RComp.GetX() + MComp.m_Velocity);
			}
		}
		CurrEntity++;
	}
	
}
void MovementSystem::Render(Graphics* g)
{
}

