#pragma once
#include "Box.h"
#include "ItemInBox.h"
#include "ResourcesManager.h"


class LuckyBox
{
	Box*					m_box;
	ItemInBox*				m_item;
public:
	LuckyBox(ItemsType type, int countCoin);
	LuckyBox(ItemsType type);

	void					update();
	void					draw(Graphics* g);

	void					setPosition(int x, int y);
	void					setCollision(bool collision);

	ItemInBox*				getItem(){ return m_item; }
	Box*					getBox(){ return m_box; }

	bool					getActive(){ return m_box->getActive(); }
	void					setActive(bool x){ m_box->setActive(x); }

	void					setCamera(int vpx, int vpy);
	~LuckyBox();
};

