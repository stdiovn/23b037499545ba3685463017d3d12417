#ifndef StaticObject_h__
#define StaticObject_h__

#include "BrickBreaker/GameObject/Object.h"

class StaticObject : public Object
{
public:
	virtual			~StaticObject(){};

	virtual void	draw(Graphics* g)		= 0;

	virtual void	update(float deltaTime)	= 0;

};

#endif // StaticObject_h__
