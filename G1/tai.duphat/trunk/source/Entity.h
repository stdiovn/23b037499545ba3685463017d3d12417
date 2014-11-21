#ifndef _Entity_
#define _Entity_
#include "Component.h"
#include "STDIO_FW\Video\Image.h"
#include <stdio.h>
#include <vector>

using namespace stdio_fw;

class Entity
{
protected:
	std::vector<Component*> m_Entity;
	std::vector<IDComponent> m_Id;
public:
	Entity();

	int getCountComponent()
	{
		return m_Id.size();
	}
	void addComponent(Component* component, IDComponent id);
	Component* getComponent(IDComponent id);
	void ClearAll();
};

#endif