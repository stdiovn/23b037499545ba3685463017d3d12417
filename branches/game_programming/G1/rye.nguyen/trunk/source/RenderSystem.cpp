#include "stdafx.h"

#include "RenderSystem.h"

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{
	SAFE_DEL(m_instance);
}

RenderSystem* RenderSystem::m_instance = 0;

RenderSystem* RenderSystem::GetInstance()
{
	if(!m_instance)
		m_instance = new RenderSystem();

	return m_instance;
}

void RenderSystem::Render(Graphics* g)
{

}