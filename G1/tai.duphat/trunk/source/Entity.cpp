#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
}

void Entity::addComponent(Component* component, IDComponent id)
{
	m_Entity.push_back(component);
	m_Id.push_back(id);
}

Component* Entity::getComponent(IDComponent id)
{
	for (int i = 0; i < m_Id.size(); i++)
	{
		if (m_Id[i] == id)
		{
			return m_Entity[i];
		}
	}

	return NULL;
}

void Entity::ClearAll()
{
	for (int i = 0; i < m_Entity.size(); i++)
	{
		delete m_Entity[i];
	}
}