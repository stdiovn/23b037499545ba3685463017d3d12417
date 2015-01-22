#pragma once
#include "Box.h"
#include "ItemInBox.h"

class Brick
{
	Box*			m_brick;
	ItemInBox*				m_item;
public:
	Brick();
	~Brick();
};

