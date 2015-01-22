#pragma once
#include "State.h"
#include "Enemy.h"

class FlowerIdle : public State<Enemy>
{
	static FlowerIdle*	m_instance;
public:
	FlowerIdle(){}
	virtual ~FlowerIdle(){}

	static FlowerIdle*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);
};


class FlowerGrow : public State<Enemy>
{
	static FlowerGrow*	m_instance;

	void				NextFrame(Enemy* enemy);
public:
	FlowerGrow(){}
	virtual ~FlowerGrow(){}

	static FlowerGrow*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};

class FlowerDead : public State<Enemy>
{
	static FlowerDead*	m_instance;

	void			NextFrame(Enemy* enemy);
public:
	FlowerDead(){}
	virtual ~FlowerDead(){}

	static FlowerDead*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};