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
	Vector2D			m_default_veloc;

	bool				m_is_active;

	Image*				m_image;
public:
	Ball();
	virtual				~Ball();

	virtual void		Init();
	void				Init(char* path, Vector2D veloc);
	virtual void		Release();

	virtual void		Update();
	virtual void		Render(Graphics* g);

	void				CheckCollisionWithScreen();
	bool				IsCollisionWithObject(Rect object, int velocity);

	bool				IsActive();
	void				Reset();
};

#endif