#include "stdafx.h"
#include "MoveableObject.h"


CMoveableObject::CMoveableObject()
{
}


CMoveableObject::~CMoveableObject()
{
}


Rect CMoveableObject::getSizeRectOfObject()
{
	if (!m_textureVector.empty())
		return m_bound;
	else
	{
		MessageBox(NULL, "Error get size Rect Object", NULL, MB_OK);
		exit(0);
	}
	
}