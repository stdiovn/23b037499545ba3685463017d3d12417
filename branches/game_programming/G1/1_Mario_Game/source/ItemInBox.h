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

	int							m_timeAnimation;

	int							m_vpx, m_vpy;
	bool						m_isCollision;
public:
	ItemInBox(Image* spritesheet, std::vector<Frame>* frameList, ItemsType type);
	~ItemInBox();

	StateMachine<ItemInBox>*	getStateMachine(){ return m_stateMachine; };
	void		setCurrentFrame(int frame){ m_currentFrame = frame; }

	void		update();
	void		draw(Graphics* g);

	bool		finishAnimation(){ return m_finishAnimation; }
	void		setFinishAnimation(bool x){ m_finishAnimation = x; }

	void		setTimeAnimation(int x){ m_timeAnimation = x; }
	int			getTimeAnimation(){ return m_timeAnimation; }

	bool		getCollision(){ return m_isCollision; }
	void		setCollision(bool x){ m_isCollision = x; }

	void		setCamera(int vpx, int vpy);

	void		setItemsType(ItemsType type);
};
