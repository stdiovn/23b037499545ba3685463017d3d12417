#pragma once
#include <list>
#include "Entity.h"

class EntityManager
{
private:
	std::list<Entity*>		m_EntityList;
	static EntityManager*	m_Instance;

public:
	EntityManager();
	~EntityManager();

	static EntityManager* GetInstance();
	std::list <Entity*>& GetEntityList();
	void Init();
	void AddEntity(Entity* E);
	void Release();
	void Update();
	void Render(Graphics* G);
	void ClearEntity();
};

