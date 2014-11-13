#pragma once

#include "Entity.h"

class Factory
{
private:
	static Factory*	m_instance;
public:
	Factory();
	virtual			~Factory();

	virtual void	Init();
	virtual void	Release();

	static Factory*	GetInstance();

	Entity*			CreateMushroom();
	Entity*			CreatePlayer();

};