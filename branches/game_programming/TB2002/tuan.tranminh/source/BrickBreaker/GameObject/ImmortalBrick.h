#ifndef ImmortalBrick_h__
#define ImmortalBrick_h__

#include "BrickBreaker/GameObject/Brick.h"

#define IMMORTAL_BRICK_COLOR	0xFF00FFFF

class ImmortalBrick : public Brick
{
public:
	ImmortalBrick(Vector2 position);
	virtual ~ImmortalBrick();

	virtual void draw(Graphics* g);

	virtual void update(float deltaTime);

	virtual bool damaged();

	virtual bool outOfScreenHandling(Vector2 moveDistance);

			void setImmortalBrickProperties(Vector2 position);

private:
	bool _isDead;
};

#endif // ImmortalBrick_h__
