#ifndef __COMMONSTRUCTURE_H__
#define __COMMONSTRUCTURE_H__

#define CHANGE_DIRECTION(x) x*= -1


enum e_Direction
{
	NONE_DIRECTION = 0,
	LEFT_DIRECTION,
	RIGHT_DIRECTION,
	TOP_DIRECTION,
	BOT_DIRECTION
};

enum e_Sreen
{
	POSITION_TOP_SCREEN		= 0,
	POSITION_BOT_SCREEN		= 600,
	POSITION_LEFT_SCREEN	= 0,
	POSITION_RIGHT_SCREEN	= 800
};

enum e_DeltaDistance
{
	DELTA_X = 20,
	DELTA_Y = 20
};

enum e_StateGame
{
	START_STATEGAME,
	END_CONGTRATULATION_STATEGAME,
	END_GAMEOVER_STATEGAME
};

enum e_StateBall
{
	STAND_BALL		= 0
};

enum e_StateBrick
{
	DESTROY_BRICK_STATE = -1,
	WOOD_BRICK_STATE	=  0,
	STONE_BRICK_STATE	=  1
};
enum e_SizeBall
{
	WIDTH_BALL		= 80,
	HEIGHT_BALL		= 80
};

enum e_KindOfBall
{
	KATANA
};

enum e_KindOfItem
{
	NONE_ITEM = 0,
	DESTROY_ITEM,
	CLONE_ITEM,
	IMPERISHABLE_ITEM
};

enum e_KindOfBrick
{
	WOOD_BRICK,
	STONE_BRICK
};

enum EStateKey
{
	KEY_PRESS		= 1,
	KEY_RELEASE		= 0
};

#define WOOD_FILE_PATH		"Mozukai.png"
#define STONE_FILE_PATH		"Iwa.png"
#define BALL_FILE_PATH		"Suriken.png"
#define BAR_FILE_PATH		"Katana.png"
#endif

