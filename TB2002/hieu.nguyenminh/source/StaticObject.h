#pragma once
#include "Object.h"

using namespace stdio_fw;


class StaticObject :
	public Object
{
protected:
	Vec2 mPosition;
public:
	StaticObject();
	virtual void Update() = 0;
	virtual void Render(Graphics *g) = 0;
	virtual ~StaticObject();
};

