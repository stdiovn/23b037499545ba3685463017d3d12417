#pragma once
#include "State.h"
#include "Bullet.h"

class BulletIdle : public State<Bullet>
{
	static BulletIdle*	m_instance;
public:
	BulletIdle(){}
	virtual ~BulletIdle(){}

	static BulletIdle*	getInstance();

	virtual void		enter(Bullet* bullet);
	virtual void		execute(Bullet* bullet);
	virtual void		exit(Bullet* bullet);
};


class BulletMoving : public State<Bullet>
{
	static BulletMoving*	m_instance;

	double					alpha;
	int						m_velocity_x;
	void					NextFrame(Bullet* enemy);
public:
	BulletMoving(){}
	virtual ~BulletMoving(){}

	static BulletMoving*	getInstance();

	virtual void		enter(Bullet* enemy);
	virtual void		execute(Bullet* enemy);
	virtual void		exit(Bullet* enemy);
};


class BulletExplode : public State<Bullet>
{
	static BulletExplode*	m_instance;

	void				NextFrame(Bullet* enemy);
public:
	BulletExplode(){}
	virtual ~BulletExplode(){}

	static BulletExplode*	getInstance();

	virtual void		enter(Bullet* enemy);
	virtual void		execute(Bullet* enemy);
	virtual void		exit(Bullet* enemy);
};
