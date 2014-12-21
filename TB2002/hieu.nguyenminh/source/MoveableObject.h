#pragma once
#include "Object.h"

using namespace stdio_fw;

class MoveableObject :
	public Object
{
protected:
	Vec2 mPosition;
	Image **mImage;
	bool _isDead;
	float _vx;
	float _vy;
public:
	MoveableObject();
	~MoveableObject();
	virtual void Dead();
	virtual void Update();
	virtual void Render(Graphics *g);
	virtual Rect getBound();
};

