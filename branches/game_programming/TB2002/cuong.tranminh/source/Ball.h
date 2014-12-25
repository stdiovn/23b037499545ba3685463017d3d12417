#pragma once
#include "DynamicObject.h"
enum DIRECTION
{
	WN,
	EN,
	WS,
	ES,
};
class Ball :
	public DynamicObject
{
	DIRECTION dBall;
public:


	void Init();
	void Update();
	void Render(Graphics*);
	void setDirection(DIRECTION);
	DIRECTION getDirection();
	Ball();
	~Ball();
};

