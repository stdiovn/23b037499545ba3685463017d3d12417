#pragma once

using namespace stdio_fw;
class BaseObject
{
private:
	bool		m_isActive;

	Rect		m_currentFrame;
public:
	BaseObject();
	virtual ~BaseObject();

	virtual void		update() = 0;
	virtual void		draw(Graphics* g) = 0;

	virtual Rect		getRect(){ return m_currentFrame; }
	virtual bool		isCollide(Rect rect){ return g_isCollide(this->m_currentFrame, rect); }
};