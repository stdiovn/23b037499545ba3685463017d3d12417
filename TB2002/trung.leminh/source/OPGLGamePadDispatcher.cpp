#include "stdafx.h"
#include "OPGLGamePadDispatcher.h"


COPGLGamePadDispatcher::COPGLGamePadDispatcher()
{
}


COPGLGamePadDispatcher::~COPGLGamePadDispatcher()
{
}

//------------------------------------------------------------------------------------------------------------------//
/// @description :	descripting all button in gamepad. We create list button and all button that it's release status.
/// @parameter	 :	Nothing
/// @return		 :	void
/// @warning	 :	No
//------------------------------------------------------------------------------------------------------------------//
void COPGLGamePadDispatcher::Init()
{
	m_listButton.insert(pair<char*, EStateKey>("KEY_START", EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_EXIT",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_LEFT",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_RIGHT", EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_UP",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_DOWN",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_W",		EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_A",		EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_S",		EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_D",		EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_L1",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_L2",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_R1",	EStateKey::KEY_RELEASE));
	m_listButton.insert(pair<char*, EStateKey>("KEY_R2",	EStateKey::KEY_RELEASE));

}

//---------------------------------------------------------------------------------------------------------------------//
/// @description :	Update list status button and implement respective event 
/// @param		 :	float deltaTime 's time for update
/// @return		 :	void
/// @warning	 :	Nothing now.
//---------------------------------------------------------------------------------------------------------------------//
void COPGLGamePadDispatcher::Update(float deltaTime)
{
	if (m_listButton["KEY_START"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_EXIT"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_LEFT"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_RIGHT"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_UP"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_DOWN"] == KEY_PRESS)
	{
	}

	if (m_listButton["KEY_W"] == KEY_PRESS)
	{
	}

}

void COPGLGamePadDispatcher::RemoveEvent()
{

}

void COPGLGamePadDispatcher::Release()
{

}

void COPGLGamePadDispatcher::AddEvent()
{

}