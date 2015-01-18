#ifndef __C_OBJECT_H_
#define __C_OBJECT_H_

#include "STDIO_FW\stdio_fw.h"

using namespace stdio_fw;

class CObjects
{
public:
	CObjects();
	CObjects(int positionX, int positionY, int velocityX, int velocityY, Image* texture);
	~CObjects();
	virtual ErrorCode	Init()					= 0;
	virtual void		Update(float deltaTime)	= 0;
	virtual void		UpdateEventHandle()		= 0;		// Update event of device( Keyboard, mouse ... )
	virtual void		Render(Graphics* g)		= 0;
	virtual void		Release()				= 0;
			Rect		getSizeRectOfObject();

protected:
	int			m_posX,
				m_posY,				// don't know how to use vector2
				m_velX,
				m_velY;

	Image*		m_texture;
};

#endif