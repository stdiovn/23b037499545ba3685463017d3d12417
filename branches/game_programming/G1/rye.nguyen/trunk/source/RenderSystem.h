#pragma once

#include "STDIO_FW\Video\Graphics.h"
using namespace stdio_fw;

class RenderSystem
{
private:
	static RenderSystem*	m_instance;
public:
	RenderSystem();
	virtual ~RenderSystem();

	static RenderSystem*	GetInstance();

	virtual void			Init();
	virtual void			Release();

	virtual void			Render(Graphics* g);
};