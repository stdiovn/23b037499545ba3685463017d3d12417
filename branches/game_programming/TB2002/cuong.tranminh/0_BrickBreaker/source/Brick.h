#pragma once
#include "DynamicObject.h"


class Brick :
	public DynamicObject
{
	float possion;
public:
	void Init();
	void Update();
	void Render(Graphics* g);
	Brick(float);
	Brick();
	~Brick();
};
