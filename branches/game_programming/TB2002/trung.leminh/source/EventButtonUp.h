#pragma once
#include "E:\OPENGLES\source\EventButton.h"
class CEventButtonUp :
	public CEventButton
{
public:
	CEventButtonUp();
	~CEventButtonUp();

	virtual void			AddEvent()				override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()			override;
};

