#include "stdafx.h"
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{

}

DynamicObject::~DynamicObject()
{
}

Rect DynamicObject::getRect()
{
	return rDynamicObject;
}


void DynamicObject::setalive(bool b)
{
	alive = b;
}
bool DynamicObject::getalive()
{
	return alive;
}