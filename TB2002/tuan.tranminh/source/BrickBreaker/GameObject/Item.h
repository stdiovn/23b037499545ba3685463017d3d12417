#ifndef Item_h__
#define Item_h__

#include "BrickBreaker/GameObject/MoveObject.h"

#define ITEM_FALL_SPEED	50

class Item : public MoveObject
{
	virtual void draw(Graphics* g);

	virtual void update(float deltaTime);

	virtual bool outOfScreenHandling(Vector2 moveDistance);

};


#endif // Item_h__