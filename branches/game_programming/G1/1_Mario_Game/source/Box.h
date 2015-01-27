#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "BaseObject.h"
#include "StateMachine.h"


using namespace stdio_fw;
class Box : public BaseObject
{
private:
	int						m_countCoin;
	bool					m_isCollision;
	bool					m_finishAnimation;

	int							m_timeAnimation;

	StateMachine<Box>*		m_stateMachine;

	int						m_vpx, m_vpy;
public:
	Box(Image* spritesheet, std::vector<Frame>* frameList, ItemsType type, int countCoin);
	~Box();

	StateMachine<Box>*		getStateMachine();
	void					setCurrentFrame(int frame){ m_currentFrame = frame; }

	void					update();
	void					draw(Graphics* g);

	int						getCoinInBox(){ return m_countCoin; }
	void					setCoinInBox(int x){ m_countCoin = x; }

	bool					getCollision(){ return m_isCollision; }
	void					setCollsion(bool x){ m_isCollision = x; }

	void					setTimeAnimation(int x){ m_timeAnimation = x; }
	int						getTimeAnimation(){ return m_timeAnimation; }


	bool					finishAnimation(){ return m_finishAnimation; };
	void					setFinishAnimation(bool x){ m_finishAnimation = x; }

	void					setCamera(int vpx, int vpy);
};