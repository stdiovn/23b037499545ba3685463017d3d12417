#ifndef __BALL_H__
#define __BALL_H__

#include "Object.h"
#include "support.h"

using namespace stdio_fw;

class Ball : public Object
{
private:
	Rect				m_object;
	Vector2D			m_velocity;

	bool				m_is_alive;

	Image*				m_image;
public:
	Ball();
	virtual				~Ball();

	virtual void		Init();
	virtual void		Release();

	virtual void		Update();
	virtual void		Render(Graphics* g);

	void				CheckCollisionWithScreen();
	bool				CheckCollisionWithObject(Rect object, int velocity);

	bool				IsAlive();
	void				Reset();
};

#endif