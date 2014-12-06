#ifndef __COMMONSTRUCTURE_H__
#define __COMMONSTRUCTURE_H__

#define CHANGE_DIRECTION(x) x*= -1


enum e_Direction
{
	NONE = 0,
	LEFT,
	RIGHT,
	TOP,
	BOT
};

enum e_Sreen
{
	POSITION_TOP	= 0,
	POSITION_BOT	= 600,
	POSITION_LEFT	= 0,
	POSITION_RIGHT	= 800
};

enum e_DeltaDistance
{
	DELTA_X = 10,
	DELTA_Y = 10
};

enum e_StateGame
{
	START,
	END_CONGTRATULATION,
	END_GAMEOVER
};

#endif