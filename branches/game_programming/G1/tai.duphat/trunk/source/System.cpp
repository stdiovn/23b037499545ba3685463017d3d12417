#include "stdafx.h"
#include "System.h"

void RenderFontSystem(Graphics *g, Entity *entity)
{
		if (entity->getComponent(IDComponent::COM_FONT) != NULL)
		{
			FontComponent *temp = static_cast<FontComponent*>(entity->getComponent(IDComponent::COM_FONT));
			Position *position = static_cast<Position*>(entity->getComponent(IDComponent::COM_POSITION));

			int x = position->x;
			int y = position->y;
			for (int i = 0; i < strlen(temp->m_Text); i++)
			{
				for (int j = 0; j < temp->N; j++)
				{
					if (temp->m_Text[i] == temp->m_InforFont[j].Byte)
					{
						g->drawRegion(temp->m_Image, x, y, temp->m_InforFont[j].X, temp->m_InforFont[j].Y, temp->m_InforFont[j].Width, temp->m_InforFont[j].Height);
						x += temp->m_InforFont[j].Width;
						break;
					}
				}
			}
	}
}

void RenderAnimationSystem(Graphics *g, Entity *entity)
{
	SpriteComponent* sprite = static_cast<SpriteComponent*>(entity->getComponent(IDComponent::COM_SPRITE));
	if (sprite != NULL)
	{
		Position* position = static_cast<Position*>(entity->getComponent(IDComponent::COM_POSITION));
		sprite->m_Src_x = (sprite->m_Id % sprite->m_SpritePerCow) * sprite->m_Width;
		sprite->m_Src_y = (sprite->m_Id / sprite->m_SpritePerCow) * sprite->m_Height;

		g->drawRegion(sprite->m_Image, position->x, position->y, sprite->m_Src_x, sprite->m_Src_y, sprite->m_Width, sprite->m_Height);
		sprite->Next();
	}
}