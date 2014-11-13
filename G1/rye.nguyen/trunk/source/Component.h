#pragma once

#include "support.h"

#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

struct Component
{
	ComponentType	m_type;

	Component(){}
	virtual ~Component(){}
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
	~Transform()
	{
		SAFE_DEL(m_position);
	}
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
	~Movement()
	{
		SAFE_DEL(m_veloc);
	}
};



struct Renderer : public Component
{
	Image*			m_image;

	Renderer(Image* image)
	{
		m_image = image;
	}
	~Renderer()
	{
		m_image->unloadImage();
		SAFE_DEL(m_image);
	}
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
	~Animation()
	{
		while(!m_image_list->empty())
		{
			m_image_list->back()->unloadImage();
			SAFE_DEL(m_image_list->back());
			m_image_list->pop_back();
		}

		SAFE_DEL(m_image_list);
	}
};