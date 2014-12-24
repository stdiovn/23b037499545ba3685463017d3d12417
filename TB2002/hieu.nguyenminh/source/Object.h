#pragma once

using namespace stdio_fw;

class Object
{
public:
	Object();
	virtual void Update(float deltaTime) = 0;
	virtual void Render(Graphics *g) = 0;
	virtual ~Object();
};

