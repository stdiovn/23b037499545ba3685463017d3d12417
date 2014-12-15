#ifndef Object_h__
#define Object_h__

#include "stdio_fw.h"

#include "BrickBreaker/Core/Vector2.h"

using namespace stdio_fw;

class Object
{
public:
	virtual void draw(Graphics* g)			= 0;
	virtual void update(float deltaTime)	= 0;
};

#endif // Object_h__
