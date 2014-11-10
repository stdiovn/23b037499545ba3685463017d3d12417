#pragma once

#include "Component.h"

class Entity
{
private:
	EntityType			m_type;
	Transform*			m_transform;
	Movement*			m_move;
	Renderer*			m_render;
	Animation*			m_animation;
public:
	Entity();
	~Entity();
	
	void				Init(EntityType type);
	void				Release();

	/*void				SetComponent(Component* component, ComponentType type);
	Component*			GetComponent(ComponentType type);

	Component**			GetListComponent();*/

	Transform*			GetTransform();
	Movement*			GetMovement();
	Renderer*			GeRenderer();
	Animation*			GetAnimation();

	void				SetTransform(int x, int y, float scale = 1.0f);
	void				SetMovement(int velocx, int velocy, int accel = 0);
	void				SetRenderer(Image* image);
	void				SetAnimation(ImageList* image_list);
};