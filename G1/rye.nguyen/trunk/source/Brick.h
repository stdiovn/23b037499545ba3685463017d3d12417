#ifndef __BRICK_H__
#define __BRICK_H__

#include "Object.h"
#include "support.h"

using namespace stdio_fw;

class Brick : public Object
{
private:
	Rect				m_object;
	bool				m_is_active;
	
	Image*				m_image;
public:
	Brick();
	virtual				~Brick();

	virtual void		Init();
	void				Init(int position_x, int position_y, int width, int height);
	virtual void		Release();

	virtual void		Update();
	virtual void		Render(Graphics* g);

	Rect				GetRect();
	bool				IsActive();

	void				Activate();
	void				DeActivate();
};

#endif