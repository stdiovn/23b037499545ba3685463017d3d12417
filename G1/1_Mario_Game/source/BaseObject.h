#pragma once


////////////////////////////////////////////////////////////
//Coder: Rye
//Purpose: Base Object for inheritance
#include <vector>

#include "support.h"

#include "STDIO_FW\stdio_fw.h"
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\Video\Graphics.h"
using namespace stdio_fw;
class BaseObject
{
protected:
	Image*					m_spriteSheet;
	std::vector<Frame>*		m_frameList;
	int			m_currentFrame;

	Vec2		m_veloc;
	Vec2		m_position;
	Vec2		m_worldPosition;
	uint		m_flipping;

	DWORD		m_elapseFrameTime;
	DWORD		m_lastTime;

	bool		m_isActive;
public:
	BaseObject(Image* spritesheet, std::vector<Frame>* frameList)
		: m_spriteSheet(spritesheet), m_frameList(frameList){
		m_flipping = 0U;
		m_elapseFrameTime = 0;
		m_lastTime = GetTickCount();
	}
	virtual ~BaseObject(){}

	virtual void		update() = 0;
	virtual void		draw(Graphics* g) = 0;

	virtual Rect		getRect(){ return m_frameList->at(m_currentFrame).m_frameRect; }

	virtual Vec2		getVeloc(){ return m_veloc; }
	virtual void		setVeloc(int x, int y){ m_veloc = Vec2(x, y); }

	virtual Vec2		getPosition(){ return m_position; }
	virtual void		setPosition(int x, int y){ m_position = Vec2(x, y); }

	virtual Vec2		getWorldPosition(){ return m_worldPosition; }
	virtual void		setWorldPosition(int x, int y){ m_worldPosition = Vec2(x, y); m_position.y = m_worldPosition.y; }
};
////////////////////////////////////////////////////////////