#pragma once
#include "EventButton.h"
class CEventButtonRight :
	public CEventButton
{
public:
	CEventButtonRight();
	~CEventButtonRight();

	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()								override;

};

