#pragma once
#include "State.h"
#include "Enemy.h"

class TurtleMoving : public State<Enemy>
{
	static TurtleMoving*	m_instance;

	void			NextFrame(Enemy* enemy);
public:
	TurtleMoving(){}
	virtual ~TurtleMoving(){}

	static TurtleMoving*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};


class TurtleRoll : public State<Enemy>
{
	static TurtleRoll*	m_instance;
public:
	TurtleRoll(){}
	virtual ~TurtleRoll(){}

	static TurtleRoll*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};

class TurtleRollMoving : public State<Enemy>
{
	static TurtleRollMoving*	m_instance;
public:
	TurtleRollMoving(){}
	virtual ~TurtleRollMoving(){}

	static TurtleRollMoving*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};

class TurtleDead : public State<Enemy>
{
	static TurtleDead*	m_instance;
public:
	TurtleDead(){}
	virtual ~TurtleDead(){}

	static TurtleDead*	getInstance();

	virtual void		enter(Enemy* enemy);
	virtual void		execute(Enemy* enemy);
	virtual void		exit(Enemy* enemy);

};
