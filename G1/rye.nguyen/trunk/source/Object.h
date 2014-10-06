#ifndef __OBJECT_H__
#define __OBJECT_H__

using namespace stdio_fw;

class Object
{
public:
	Object(){}
	virtual				~Object(){}

	virtual void		Init() = 0;
	virtual void		Release() = 0;

	virtual void		Update() = 0;
	virtual void		Render(Graphics* g) = 0;
};

#endif