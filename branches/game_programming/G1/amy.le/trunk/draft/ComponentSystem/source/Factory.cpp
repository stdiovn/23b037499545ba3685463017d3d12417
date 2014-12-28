#include "stdafx.h"
#include "Factory.h"
#include "Support.h"
Factory::Factory()
{

}

Factory::~Factory()
{

}

void Factory::Init()
{
	m_Entity = new Entity;
	m_Entity->Init();
}

void Factory::Release()
{
	m_Entity->Release();
}

Entity* Factory::CreateTart()
{
	Entity* entity = new Entity();
	entity->Init();
	entity->SetID(1);
	entity->AddAnimation(ImgList);
	return entity;
}

Entity* Factory::CreateTurtle()
{
	Entity* entity = new Entity();
	entity->Init();
	entity->SetID(2);
	entity->AddRender(TurtleImage, 50, 300);
	entity->AddMove(2, 60, 1, 300, 400);
	return entity;
}