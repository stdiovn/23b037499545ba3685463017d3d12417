#pragma once
#include "MoveableObject.h"
#include "CommonStructure.h"
class CBrick :
	public CMoveableObject
{
public:
	CBrick();
	~CBrick();
	s_vector2D	 getPosition();
	void		 setPosition(s_vector2D position);
	e_StateBrick getStateBrick();
	void		 setStateBrick(e_StateBrick stateBrick);
protected:
	e_StateBrick			m_healthyBrick;
};

