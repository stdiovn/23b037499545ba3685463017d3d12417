#pragma once

#include "Entity.h"

class Factory
{
private:
	static Factory*	m_instance;
public:
	Factory();
	virtual			~Factory();

	static Factory*	GetInstance();

	Entity*			CreateMushroom();

};