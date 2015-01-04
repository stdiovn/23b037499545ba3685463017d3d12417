#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
//Purpose: Game support

using namespace stdio_fw;
struct Frame
{
	std::string		m_id;
	Rect			m_frameRect;
};

struct InformationObject
{
	int		m_id;
	Rect	m_rect;
};


enum GameState
{
	STATE_PLAY,
	STATE_WIN,
	STATE_GAME_OVER,
};

enum SpriteSheet
{
	SHEET_MARIO,
	SHEET_ENEMIES,
	SHEET_ITEM,
	SHEET_TILESET,
};

enum MarioState
{
	MS_STANDING,
	MS_RUNNING,
	MS_FASTRUNNING,
	MS_JUMPING,
	MS_FALLING,
	MS_SITTING,
};

enum MarioSheet
{
	BIG_MARIO_STAND	= 0,
	BIG_MARIO_RUN = 1,
	BIG_MARIO_CHANGE_DIR = 4,
	BIG_MARIO_JUMP = 5,
	BIG_MARIO_SIT = 6,
	MARIO_STAND	= 7,
	MARIO_RUN = 8,
	MARIO_CHANGE_DIR = 11,
	MARIO_JUMP = 12,
	MARIO_DIE = 13,
	SUPER_MARIO_STAND = 14,
	SUPER_MARIO_RUN	= 15,
	SUPER_MARIO_CHANGE_DIR = 18,
	SUPER_MARIO_JUMP = 19,
	SUPER_MARIO_SIT	= 20,
};

enum Direction
{
	DIR_UNKNOWN = -1,
	DIR_NONE = 0,
	DIR_TOP,
	DIR_BOTTOM,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_TOP_LEFT,
	DIR_BOTTOM_LEFT,
	DIR_TOP_RIGHT,
	DIR_BOTTOM_RIGHT
};

enum Location
{
	LOC_ON_GROUND,
	LOC_IN_AIR
};

Direction	g_isCollide(Rect st, Rect nd, Vec2 stVeloc, Vec2 ndVeloc = Vec2(0, 0));
int			g_getNumber(char* s);
////////////////////////////////////////////////////////////