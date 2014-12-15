#ifndef Brick_h__
#define Brick_h__

#include "MoveObject.h"

#define BRICK_SIZE_WIDTH	40
#define BRICK_SIZE_HEIGHT	10

#define BRICK_DESTROYED		true
#define BRICK_STILL_LIVE	false

enum BrickType
{
	BRICK_NONE = -1,
	BRICK_NORMAL = 0,
	BRICK_IMMORTAL,
	BRICK_EXPLODE,
	NUM_OF_BRICK_TYPE
};

class Brick : public MoveObject
{
public:
	virtual void	draw(Graphics* g)			= 0;
	virtual void	update(float deltaTime)		= 0;
	virtual bool	damaged()					= 0;

			void	setBrickProperties(Vector2 Position);
};

#endif // Brick_h__
