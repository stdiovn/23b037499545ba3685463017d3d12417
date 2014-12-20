#pragma once
#include "E:\OPENGLES\source\EventButton.h"
class CEventButtonStart :
	public CEventButton
{
public:
	CEventButtonStart();
	~CEventButtonStart();

	virtual void			AddEvent()				override;
	virtual void			UpdateEvent(float, CMoveableObject*)		override;
	virtual void			RemoveEvent()			override;

};

