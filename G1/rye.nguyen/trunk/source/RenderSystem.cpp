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

		/////////////////////////////////////////////////////////////////////
		//Render text
		Label* label = dynamic_cast<Label*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_LABEL));
		if(label)
		{
			Transform* transform = dynamic_cast <Transform*>(entity._Ptr->_Myval->GetComponent(ComponentType::COM_TRANSFORM));
			int label_size = strlen(label->m_text);
			int char_pos;
			int pos = transform->m_position->x;
			for(int i = 0; i < label_size; i++)
			{
				char_pos = 0;
				while(label->m_char[char_pos] != label->m_text[i])
					char_pos++;

				/*g->drawRegion	(	
									label->m_font, pos, transform->m_position->y + label->m_char_offset[char_pos],
									label->m_char_map[char_pos]->x, label->m_char_map[char_pos]->y, 
									label->m_char_map[char_pos]->width, label->m_char_map[char_pos]->height
								);*/

				pos += label->m_char_map[char_pos]->width + label->m_char_distance;
			}
		}
		/////////////////////////////////////////////////////////////////////

		entity++;
	}
}