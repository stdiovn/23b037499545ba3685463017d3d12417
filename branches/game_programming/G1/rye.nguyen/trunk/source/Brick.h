#ifndef __BRICK_H__
#define __BRICK_H__

#include "Object.h"
#include "support.h"

using namespace stdio_fw;

class Brick : public Object
{
private:
	Rect				m_object;
	Image*				m_image1;
	Image*				m_image2;
	Image*				m_image;

	int					m_lives;
	bool				m_is_active;
public:
	Brick();
	virtual				~Brick();

	virtual void		Init();
	void				Init(char* path1, char* path2, int position_x, int position_y, int width, int height);
	virtual void		Release();

	virtual void		Update();
	virtual void		Render(Graphics* g);

	int					GetLives();
	void				SetLive(int value);

	Rect				GetRect();
	bool				IsActive();

	void				Activate();
	void				DeActivate();
};

#endif