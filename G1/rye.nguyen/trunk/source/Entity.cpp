#include "stdafx.h"

#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Init(EntityType type)
{
	m_transform = NULL;
	m_move = NULL;
	m_render = NULL;
	m_animation = NULL;

	m_type = type;
}

void Entity::Release()
{
	//SAFE_DEL_ARR(m_component_list);
}

Transform* Entity::GetTransform()
{
	return m_transform;
}

Movement* Entity::GetMovement()
{
	return m_move;
}

Renderer* Entity::GeRenderer()
{
	return m_render;
}

Animation* Entity::GetAnimation()
{
	return m_animation;
}

void Entity::SetTransform(int x, int y, float scale)
{
	m_transform = new Transform(x, y, scale);
}

void Entity::SetMovement(int velocx, int velocy, int accel)
{
	m_move = new Movement(velocx, velocy, accel);
}

void Entity::SetRenderer(Image* image)
{
	m_render = new Renderer(image);
}

void Entity::SetAnimation(ImageList* image_list)
{
	m_animation = new Animation(image_list);
}