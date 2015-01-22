#pragma once
#include "BaseObject.h"
#include "StateMachine.h"


using namespace stdio_fw;
class ItemInBox : public BaseObject
{
private:
	StateMachine<ItemInBox>*	m_stateMachine;

	ItemsType					m_type;
	bool						m_finishAnimation;

	int							m_vpx, m_vpy;
public:
	ItemInBox(Image* spritesheet, std::vector<Frame>* frameList, ItemsType type);
	~ItemInBox();

	StateMachine<ItemInBox>*	getStateMachine(){ return m_stateMachine; };
	void		setCurrentFrame(int frame){ m_currentFrame = frame; }

	void		update();
	void		draw(Graphics* g);

	void		setActive(bool active){ m_isActive = active; };
	bool		getActive(){ return m_isActive; }

	bool		finishAnimation(){ return m_finishAnimation; }
	void		setFinishAnimation(bool x){ m_finishAnimation = x; }

	void		setCamera(int vpx, int vpy);
};
