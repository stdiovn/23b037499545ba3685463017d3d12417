#pragma once
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "EntityManager.h"
class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	void Update();
	void Render(Graphics* g);

};

