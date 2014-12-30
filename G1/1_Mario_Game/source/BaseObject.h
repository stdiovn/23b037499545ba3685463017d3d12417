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
private:
	Image*					m_spriteSheet;
	std::vector<Frame>*		m_frameList;
	int			m_currentFrame;

	bool		m_isActive;
public:
	BaseObject(Image* spritesheet, std::vector<Frame>* frameList)
		: m_spriteSheet(spritesheet), m_frameList(frameList){}
	virtual ~BaseObject(){}

	virtual void		update() = 0;
	virtual void		draw(Graphics* g) = 0;

	virtual Rect		getRect(){ return m_frameList->at(m_currentFrame).m_frameRect; }
	virtual bool		isCollide(Rect rect){ return g_isCollide(this->m_frameList->at(m_currentFrame).m_frameRect, rect); }
};
////////////////////////////////////////////////////////////