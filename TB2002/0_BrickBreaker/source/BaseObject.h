#ifndef _BASEOBJETC_H_
#define _BASEOBJECT_H_

#include "Images.h"
using namespace stdio_fw;

class BaseObject
{
protected:
	Image* im;
	virtual void Init() = 0;
	virtual void Render(Graphics* g) = 0;

public:
	BaseObject();
	~BaseObject();
};

#endif