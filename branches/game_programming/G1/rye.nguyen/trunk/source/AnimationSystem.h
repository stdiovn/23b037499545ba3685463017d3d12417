#pragma once

#include "STDIO_FW\Video\Graphics.h"
using namespace stdio_fw;

class AnimationSystem
{
private:
	static AnimationSystem*	m_instance;
public:
	AnimationSystem();
	virtual					~AnimationSystem();

	static AnimationSystem*	GetInstance();
	
	virtual void			Init();
	virtual void			Release();

	virtual void			Animation(Graphics* g);
};