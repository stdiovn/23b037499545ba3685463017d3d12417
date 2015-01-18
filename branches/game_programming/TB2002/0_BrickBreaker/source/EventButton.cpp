#include "stdafx.h"
#include "EventButton.h"


CEventButton::CEventButton()
{
	m_stateKey == KEY_PRESS;
}


CEventButton::~CEventButton()
{
	// nothing.
}

EStateKey CEventButton::getStateButton()
{
	return m_stateKey;
}

void CEventButton::setStateButton(EStateKey newState)
{
	m_stateKey = newState;
}
