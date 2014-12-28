#pragma once

using namespace stdio_fw;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void update(float deltaTime) = 0;
	virtual void render(Graphics *g) = 0;
};

