#pragma once
#include "E:\OPENGLES\source\EventButton.h"
class CEventButtonW :
	public CEventButton
{
public:
	CEventButtonW();
	~CEventButtonW();

	virtual void			AddEvent()				override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()			override;

};

