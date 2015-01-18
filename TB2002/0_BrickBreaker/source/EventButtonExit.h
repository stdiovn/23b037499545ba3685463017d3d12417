#pragma once
#include "EventButton.h"
class CEventButtonExit :
	public CEventButton
{
public:
	CEventButtonExit();
	~CEventButtonExit();

	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()								override;

};

