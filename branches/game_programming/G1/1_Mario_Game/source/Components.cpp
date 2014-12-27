#include "stdafx.h"

#include "Components.h"

/////////////////////////////////////////////////////////////////////////////
//Coder: Rye Nguyen
//Components
//Purpose: Each component has different ability.
//Add components into entity to make entity has component's ability

Transform::Transform() : m_x(0), m_y(0){}
Transform::Transform(int x, int y)
	: m_x(x), m_y(y){}



BoxCollider2D::BoxCollider2D() : m_bounding_box(Rect(0, 0, 0, 0)){}
BoxCollider2D::BoxCollider2D(Rect bounding_box) : m_bounding_box(bounding_box){}
BoxCollider2D::BoxCollider2D(int x, int y, int width, int height)
	: m_bounding_box(Rect(x, y, width, height)){}



Renderer::Renderer() : m_image(NULL){}
Renderer::Renderer(Image* image) : m_image(image){}
Renderer::~Renderer()
{
	m_image->unloadImage();
	SAFE_DEL(m_image);
}



Animation::Animation() : m_image(NULL), m_frame_count(0){}
Animation::Animation(Image* image, int frame_count) : m_image(image), m_frame_count(frame_count){}
void Animation::ChangeAnimation(Image* image, int frame_count)
{
	m_image = image;
	m_frame_count = frame_count;
}



Gun::Gun() : m_image(NULL), m_level(0), m_bullet_speed(0){}
Gun::Gun(Image* image, int level, int bullet_speed)
	: m_image(image), m_level(level), m_bullet_speed(bullet_speed){}



Move::Move() : m_image(NULL), m_veloc(0), m_accel(0), m_max_speed(0){}
Move::Move(Image* image, int veloc, int accel, int max_speed)
	: m_image(image), m_veloc(veloc), m_accel(accel), m_max_speed(max_speed){}



Jump::Jump() : m_image(NULL), m_height(0), m_veloc(0){}
Jump::Jump(Image* image, int height, int veloc)
	: m_image(image), m_height(height), m_veloc(veloc){}

/////////////////////////////////////////////////////////////////////////////