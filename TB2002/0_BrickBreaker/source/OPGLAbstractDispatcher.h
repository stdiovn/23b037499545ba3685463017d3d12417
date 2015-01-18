#ifndef __OPGL_ABS_DISPATCHER_H__
#define __OPGL_ABS_DISPATCHER_H__

class COPGLAbstractDispatcher
{
public:
	COPGLAbstractDispatcher();
	~COPGLAbstractDispatcher();

	virtual void Init()			= 0;
	virtual void Update(float)	= 0;
	virtual void Release()		= 0;

	virtual void AddEvent()		= 0;
	virtual void RemoveEvent()	= 0;
};

#endif