#ifndef __EVENT_BUTTON_H_
#define __EVENT_BUTTON_H_
#include "CommonStructure.h"
#include "MoveableObject.h"
class CEventButton
{
public:
	CEventButton();
	~CEventButton();

	virtual void			AddEvent()										= 0;
	virtual void			UpdateEvent(float				deltaTime,
										CMoveableObject*	movableObject)	= 0;
	virtual void			RemoveEvent()									= 0;
	
			EStateKey		getStateButton();
			void			setStateButton(EStateKey newState);
protected:
	EStateKey m_stateKey;
};

#endif