#pragma once
#include "AbstractObject.h"
#include "Algebra.h"
class CStaticObject :
	public CAbstractObject
{
public:
	CStaticObject();
	~CStaticObject();

protected:
	s_vector2D  m_position;
	Image*		m_texture;
};

