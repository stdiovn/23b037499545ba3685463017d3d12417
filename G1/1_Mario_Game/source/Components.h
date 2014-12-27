#pragma once

/////////////////////////////////////////////////////////////////////////////
//Coder: Rye Nguyen
//Components
//Purpose: Each component has different ability.
//Add components into entity to make entity has component's ability

using namespace stdio_fw;

struct Component
{
	int			m_id;

	Component(){}
	virtual		~Component(){}
};

struct Transform : public Component
{
	int			m_x;
	int			m_y;

	Transform();
	Transform(int x, int y);
};

struct BoxCollider2D : public Component
{
	Rect		m_bounding_box;

	BoxCollider2D();
	BoxCollider2D(Rect bound);
	BoxCollider2D(int x, int y, int width, int height);
};

struct Renderer : public Component
{
	Image*		m_image;

	Renderer();
	Renderer(Image* image);
	~Renderer();
};

struct Animation : public Component
{
	Image*	m_image;
	int		m_frame_count;

	int		m_last_time;
	int		m_current_time;

	Animation();
	Animation(Image* image, int frame_count);
	void	ChangeAnimation(Image* image, int frame_count);
};

struct Gun : public Component
{
	Image*	m_image;
	int		m_level;
	int		m_bullet_speed;

	Gun();
	Gun(Image* image, int level, int bullet_speed);
};

struct Move : public Component
{
	Image*	m_image;
	int		m_veloc;
	int		m_accel;
	int		m_max_speed;

	Move();
	Move(Image* image, int veloc, int accel, int max_speed);
};

struct Jump : public Component
{
	Image*	m_image;
	int		m_height;
	int		m_veloc;

	Jump();
	Jump(Image* image, int height, int veloc);
};

/////////////////////////////////////////////////////////////////////////////