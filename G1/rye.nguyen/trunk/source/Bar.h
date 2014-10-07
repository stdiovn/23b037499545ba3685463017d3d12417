#ifndef __BAR_H__
#define __BAR_H__

#include "Object.h"
#include "support.h"

using namespace stdio_fw;

class Bar : public Object
{
private:
	Rect				m_object;
	int					m_velocity;

	Image*				m_image;

	KeyCode				m_key_press;
public:
	Bar();
	virtual				~Bar();

	virtual void		Init();
	virtual void		Release();

	virtual void		Update();
	virtual void		Render(Graphics* g);

	void				KeyPress(KeyCode key);
	int					GetVelocity();
	Rect				GetRect();

	void				Reset();
};

#endif