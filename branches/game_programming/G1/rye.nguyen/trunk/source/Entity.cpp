#include "stdafx.h"

#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Init(EntityType type)
{
	m_component_list = new Component*[ComponentType::COM_COUNT];

	for(int i = 0; i < ComponentType::COM_COUNT; i++)
		m_component_list[i] = NULL;

	m_type = type;
}

void Entity::Release()
{
	for(int i = 0; i < ComponentType::COM_COUNT; i++)
	{
		if(m_component_list[i])
			delete m_component_list[i];
	}

	SAFE_DEL_ARR(m_component_list);
}

void Entity::SetComponent(Component* component, ComponentType type)
{
	m_component_list[type] = component;
	m_component_list[type]->m_type = type;
}

Component* Entity::GetComponent(ComponentType type)
{
	return m_component_list[type];
}