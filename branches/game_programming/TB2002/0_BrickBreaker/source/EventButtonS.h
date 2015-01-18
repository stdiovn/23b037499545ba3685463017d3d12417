#pragma once
#include "EventButton.h"
class CEventButtonS :
	public CEventButton
{
public:
	CEventButtonS();
	~CEventButtonS();

	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()								override;

};

