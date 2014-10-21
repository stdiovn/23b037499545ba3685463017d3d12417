#ifndef _Ball_
#define _Ball_

#include"Entity.h"
#include <vector>
#define ImageBall "data//ball.png"

class Ball
{
	Entity *entities;

	~Ball();
public:
	Ball();
	DIR UpdateCollisionWindows(int, int);
	bool isCollsionObject(int left, int right, int top, int bottom);
	void UpdateVeclocity(int left, int right, int top, int bottom);
	void Update();
	void setPosition(int, int);
	void Render(Graphics*);
	void Clear();
};

#endif