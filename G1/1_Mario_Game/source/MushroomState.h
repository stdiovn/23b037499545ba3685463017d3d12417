#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "State.h"
#include "Enemy.h"

class MushroomMoving : public State<Enemy>
{
	static MushroomMoving*	m_instance;

	void			NextFrame(Enemy* enemy);
public:
	MushroomMoving(){}
	virtual ~MushroomMoving(){}

	static MushroomMoving*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};

class MushroomDeadByAttacked : public State<Enemy>
{
	static MushroomDeadByAttacked*	m_instance;
public:
	MushroomDeadByAttacked(){}
	virtual ~MushroomDeadByAttacked(){}

	static MushroomDeadByAttacked*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};


class MushroomDeadByJumped: public State<Enemy>
{
	static MushroomDeadByJumped*	m_instance;
public:
	MushroomDeadByJumped(){}
	virtual ~MushroomDeadByJumped(){}

	static MushroomDeadByJumped*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};