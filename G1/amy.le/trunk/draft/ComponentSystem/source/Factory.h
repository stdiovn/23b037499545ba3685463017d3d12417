 #pragma once
#include "Entity.h"
#include "Component.h"
class Factory
{
private:
	Entity* m_Entity;
public:
	Factory();
	virtual ~Factory();

	void Init();
	void Release();

	Entity* CreateTart();
	Entity* CreateTurtle();
};