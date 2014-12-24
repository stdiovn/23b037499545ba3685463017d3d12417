#pragma once
#include "Object.h"
#include "GameDefine.h"

using namespace stdio_fw;


class StaticObject :
	public Object
{
protected:
	ObjectID m_ID;
	Vec2 m_Position;
public:
	StaticObject();
	virtual void Update(float deltaTime) = 0;
	virtual void Render(Graphics *g) = 0;
	virtual ~StaticObject();
};

