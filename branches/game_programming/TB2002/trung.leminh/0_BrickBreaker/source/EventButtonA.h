#ifndef __EVENT_BUTTON_A_H__
#define __EVENT_BUTTON_A_H__

#include "EventButton.h"
class CEventButtonA :
	public CEventButton
{
public:
	CEventButtonA();
	~CEventButtonA();
	virtual void			AddEvent()									override;
	virtual void			UpdateEvent(float			 deltaTime,
										CMoveableObject* movableObject)	override;
	virtual void			RemoveEvent()								override;

};

#endif