#ifndef NormalBrick_h__
#define NormalBrick_h__

#include "BrickBreaker/GameObject/Brick.h"

#define BRICK_BORDER_COLOR	0XFFFF00FF

class NormalBrick : public Brick
{
public:
				 NormalBrick();
				 NormalBrick(Vector2 position, int healthPoints);
				~NormalBrick();

	virtual void draw(Graphics* g);

	virtual void update(float deltaTime);

	virtual bool damaged();

			void setNormalBrickProperties(Vector2 position, int healthPoints);
			
			void crash();

			virtual bool outOfScreenHandling(Vector2 moveDistance);

private:
	int healthPoints_;

	static DWORD _brickColors[];
};


#endif // NormalBrick_h__
