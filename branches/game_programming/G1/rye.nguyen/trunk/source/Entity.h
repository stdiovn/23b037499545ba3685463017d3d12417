#pragma once

#include "Component.h"

#include <vector>

class Entity
{
private:
	EntityType			m_type;
	
	Component**			m_component_list;
public:
	Entity();
	~Entity();
	
	void				Init(EntityType type);
	void				Release();

	void				SetComponent(Component* component, ComponentType type);
	Component*			GetComponent(ComponentType type);
};