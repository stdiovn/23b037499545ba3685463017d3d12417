#pragma once

#include "Object.h"
#include "GameDefine.h"

using namespace stdio_fw;


class MoveableObject :
	public Object
{
protected:
	ObjectID m_ID;
	Vec2 m_Position;
	Image **m_Image;
	bool m_isDead;
	float m_vx;
	float m_vy;
public:
	MoveableObject();
	~MoveableObject();
	virtual void Dead();
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *g);
	virtual Rect getBound();
};

