#pragma once
#include "E:\OPENGLES\source\EventButton.h"
class CEventButtonLeft :
	public CEventButton
{
public:
	CEventButtonLeft();
	~CEventButtonLeft();

	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()								override;

};
