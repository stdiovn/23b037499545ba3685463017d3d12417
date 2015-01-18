#ifndef __MOVEABLE_OBJECT_H__
#define __MOVEABLE_OBJECT_H__
#include "AbstractObject.h"
#include "Algebra.h"
#include <vector>

class CMoveableObject :
	public CAbstractObject
{
public:
	CMoveableObject();
	~CMoveableObject();
	Rect getSizeRectOfObject();
protected:
	std::vector<Image*> m_textureVector;
	s_vector2D	m_position;
	s_vector2D	m_velocity;
	Rect		m_bound;					//rectangle bound to object
};

#endif