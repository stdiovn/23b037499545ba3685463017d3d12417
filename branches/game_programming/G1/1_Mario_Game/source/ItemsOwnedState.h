#pragma once

#include "State.h"
#include "Box.h"
#include "ItemInBox.h"

class IdleBox : public State<Box>
{
	static IdleBox*	m_instance;
public:
	IdleBox(){}
	virtual ~IdleBox(){}

	static IdleBox*	getInstance();

	virtual void		enter(Box* item);
	virtual void		execute(Box* item);
	virtual void		exit(Box* item);

};


class IdleBrick : public State<Box>
{
	static IdleBrick*	m_instance;
public:
	IdleBrick(){}
	virtual ~IdleBrick(){}

	static IdleBrick*	getInstance();

	virtual void		enter(Box* item);
	virtual void		execute(Box* item);
	virtual void		exit(Box* item);

};


class BreakBrick : public State<ItemInBox>
{
	static BreakBrick*	m_instance;

	Vec2				m_position;
	int					m_timeAnimation;
public:
	BreakBrick(){}
	virtual ~BreakBrick(){}

	static BreakBrick*	getInstance();

	virtual void		enter(ItemInBox* item);
	virtual void		execute(ItemInBox* item);
	virtual void		exit(ItemInBox* item);
};


class LuckyBoxEffect : public State<Box>
{
	static LuckyBoxEffect*	m_instance;
	
	int						m_timeAnimation;
	
public:
	LuckyBoxEffect(){}
	virtual ~LuckyBoxEffect(){}

	static LuckyBoxEffect*	getInstance();

	virtual void		enter(Box* item);
	virtual void		execute(Box* item);
	virtual void		exit(Box* item);

};

class Coin : public State<ItemInBox>
{
	static Coin*	m_instance;
	int				m_timeAnimation;

	Vec2			m_position;
public:
	Coin(){}
	virtual ~Coin(){}

	static Coin*		getInstance();

	virtual void		enter(ItemInBox* item);
	virtual void		execute(ItemInBox* item);
	virtual void		exit(ItemInBox* item);
};

class MushRoomBigger : public State<ItemInBox>
{
	static MushRoomBigger*	m_instance;
	int						m_timeAnimation;

	Vec2					m_veclocity;
public:
	MushRoomBigger(){}
	virtual ~MushRoomBigger(){}

	static MushRoomBigger*		getInstance();

	virtual void		enter(ItemInBox* item);
	virtual void		execute(ItemInBox* item);
	virtual void		exit(ItemInBox* item);

};
