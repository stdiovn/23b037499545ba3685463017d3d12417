#pragma once

#include "Entity.h"

#include <list>

typedef std::list<Entity*>	EntityList;

class EntityManager
{
private:
	static EntityManager*	m_instance;
	EntityList*				m_entity_list;
public:
	EntityManager();
	virtual					~EntityManager();

	static EntityManager*	GetInstance();

	virtual void			Init();
	virtual void			Release();

	EntityList*				GetEntityList();

	void					AddEntity(Entity* entity);
	void					ReleaseAllEntity();
};