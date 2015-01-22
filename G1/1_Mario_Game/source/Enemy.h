#pragma once
#include "StateMachine.h"
#include "BaseObject.h"

class Enemy : public BaseObject
{
	StateMachine<Enemy>*		m_stateMachine;

	int							m_vpx, m_vpy;
	bool						m_isCollision;
	bool						m_beAttacked;

	EnemysType					m_typeEnemy;

	int							m_timeCountDown;
public:
	Enemy(EnemysType type, Vec2 position);


	StateMachine<Enemy>*		getStateMachine(){ return m_stateMachine; }

	void						update();
	void						draw(Graphics* g);

	bool						getCollision(){ return m_isCollision; }
	void						setCollsion(bool x){ m_isCollision = x; }

	void						setAttack(bool x){ m_beAttacked = x; }
	bool						getAttack(){ return m_beAttacked; }

	void						setCamera(int vpx, int vpy);

	EnemysType					getTypeEnemy(){ return m_typeEnemy; }

	void						setTimeCountDown(int x){ m_timeCountDown = x; }
	int							getTimeCountDown(){ return m_timeCountDown; }
	~Enemy();
};

