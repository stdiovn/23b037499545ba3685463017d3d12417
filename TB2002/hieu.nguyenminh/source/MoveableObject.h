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
	Vec2 m_Velocity;
public:
	MoveableObject();
	virtual ~MoveableObject();
	MoveableObject(Vec2 _Position, Vec2 _Velocity);
	virtual ObjectID getID();
	virtual void setDead();
	virtual void update(float deltaTime) override = 0;
	virtual void render(Graphics *g) override;
	virtual Rect getBound();
	virtual Vec2 getPositionLeftTop();
	virtual Vec2 getPositionRightBottom();
};

