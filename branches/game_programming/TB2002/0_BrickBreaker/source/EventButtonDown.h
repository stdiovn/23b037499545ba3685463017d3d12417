#pragma once
#include "EventButton.h"
class CEventButtonDown :
	public CEventButton
{
public:
	CEventButtonDown();
	~CEventButtonDown();

	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float				deltaTime,
										CMoveableObject*	obj)		override;
	virtual void			RemoveEvent()								override;

};

