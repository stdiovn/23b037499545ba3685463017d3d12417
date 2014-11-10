#pragma once

#include "support.h"

#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

struct Component
{
	ComponentType	m_type;
};

struct Transform : public Component
{
	Vector2D*		m_position;
	float			m_scale;

	Transform(int _x, int _y, float _scale = 1.0f)
	{
		m_position = new Vector2D(_x, _y);
		m_scale = _scale;
	}
	~Transform(){}
};



struct Movement : public Component
{
	MoveType		m_type;

	Vector2D*		m_veloc;
	int				m_accel;

	Movement(int velocx, int velocy, int accel = 0)
	{
		m_veloc = new Vector2D(velocx, velocy);
		m_accel = accel;

		m_type = MoveType::MOVE_NORMAL;
	}
	~Movement(){}
};



struct Renderer : public Component
{
	Image*			m_image;

	Renderer(Image* image)
	{
		m_image = image;
	}
	~Renderer(){}
};



struct Animation : public Component
{
	ImageList*			m_image_list;
	ImageListIterator	m_current_frame;

	Animation(ImageList* _image_list)
	{
		m_image_list = _image_list;
		m_current_frame = m_image_list->begin();
	}
	~Animation(){}
};