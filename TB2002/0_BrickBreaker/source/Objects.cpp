#include "stdafx.h"
#include "Objects.h"


CObjects::CObjects()
{
}


CObjects::~CObjects()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: get Information of Rect
/// @parameter:   No
/// @return type: Rect. Rect is type in stdio framework.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
Rect CObjects::getSizeRectOfObject()
{
	return Rect((float)m_posX, (float)m_posY, (float)m_texture->getWidth(), (float)m_texture->getHeight());
}
