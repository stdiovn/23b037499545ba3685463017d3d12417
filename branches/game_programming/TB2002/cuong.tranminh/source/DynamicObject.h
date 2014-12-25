#pragma once
#include "BaseObject.h"
class DynamicObject :
	public BaseObject
{
protected:
	bool alive = true;
	Rect rDynamicObject;
	virtual void Update() = 0;
public:

	Rect getRect();
	void setalive(bool);
	bool getalive();

	DynamicObject();
	~DynamicObject();
};

