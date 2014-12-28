#pragma once
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "EntityManager.h"

class AnimationSystem
{
public:
	AnimationSystem();
	~AnimationSystem();

	void Update();
	void Render(Graphics* G);
};

