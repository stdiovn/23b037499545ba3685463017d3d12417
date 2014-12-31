#ifndef __GAME_H__
#define __GAME_H__
#include "Ball.h"
#include "Bar.h"
#include "Algebra.h"
using namespace stdio_fw;
class Game : public Application
{
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);
	virtual void		Render(Graphics* g);
	virtual void		Exit();
			void		UpdateInputHandle();
protected:
			Image*		m_Image;
			e_Direction	m_direction;
			s_vector2D	m_position;
			int			m_index;
			int			m_flip;
};

#endif