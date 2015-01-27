#pragma once
#include "BaseObject.h"
#include "StateMachine.h"

class Bullet : public BaseObject
{
	StateMachine<Bullet>					*m_stateMachine;

	int										m_vpx, m_vpy;
	bool									m_isCollision;

	// time to calculate velocity 
	float									m_time;
	ShootDirection							m_shootDirection;

	// time live of bullet
	int										m_timeToLive;
public:
	Bullet(Image* spritesheet, std::vector<Frame>* frameList);
	~Bullet();


	StateMachine<Bullet>*		getStateMachine();
	void						setCurrentFrame(int frame){ m_currentFrame = frame; }

	void						setTime(float time){ m_time = time; }
	float						getTime(){ return m_time; }

	void						setTimeToLive(int time){ m_timeToLive = time; }

	void						update();
	void						draw(Graphics* g);

	bool						getCollision(){ return m_isCollision; }
	void						setCollsion(bool x){ m_isCollision = x; }

	void						setCamera(int vpx, int vpy);

	void						setShootDirection(ShootDirection dir){ m_shootDirection = dir; }
	ShootDirection				getShootDirection(){ return m_shootDirection; }
};

