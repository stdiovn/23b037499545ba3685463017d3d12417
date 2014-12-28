#pragma once
#include "STDIO_FW\Video\Graphics.h"
#include "EntityManager.h"
class MovementSystem
{
private:
public:
	MovementSystem();
	~MovementSystem();

	void Update();
	void Render(Graphics* g);
};

