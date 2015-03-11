#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "StateMachine.h"
#include "BaseObject.h"
#include"Gun.h"


using namespace stdio_fw;
class Mario : public BaseObject
{
private:
	StateMachine<Mario>*	m_stateMachine;

	int			m_lives;

	bool		m_isBig;
	bool		m_canShoot;
	bool		m_canJump;

	int			m_accel;
	bool		m_isBoost;

	Location	m_location;

	Gun*		m_gun;
public:
	Mario(Image* spritesheet, std::vector<Frame>* frameList);
	~Mario();

	void		updateVelocity();
	void		update();
	void		draw(Graphics* g);

	StateMachine<Mario>*	getStateMachine();

	bool		isBig(){ return m_isBig; }
	void		setIsBig(bool x);


	bool		canShoot(){ return m_canShoot; }
	void		setCanShoot(bool x){ m_canShoot = x; }

	void		jump(bool ability = false){ m_canJump = ability; }
	bool		canJump(){ return m_canJump; }
	
	int			getAccel(){ return m_accel; }
	bool		isBoost(){ return m_isBoost; }

	Location	getLocation(){ return m_location; }
	void		setLocation(Location location){ m_location = location; }

	void		setCurrentFrame(MarioSheet frame){ m_currentFrame = frame; }

	Gun*		getGun(){ return m_gun; }
};