#pragma once
#include "EventButton.h"
class CEventButtonD :
	public CEventButton
{
public:
	CEventButtonD();
	~CEventButtonD();
	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float				deltaTime,
										CMoveableObject*	obj)		override;
	virtual void			RemoveEvent()								override;

};

