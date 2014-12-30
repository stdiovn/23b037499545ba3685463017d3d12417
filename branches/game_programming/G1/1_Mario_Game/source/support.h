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
	int m_id;
	Rect m_llocation;
};


enum GameState
{
	STATE_PLAY,
	STATE_WIN,
	STATE_GAME_OVER,
	STATE_COUNT
};

enum SpriteSheet
{
	SHEET_MARIO,
	SHEET_ENEMIES,
	SHEET_ITEM,
	SHEET_TILESET,
	SHEET_COUNT
};

enum MarioState
{
	MS_STANDING,
	MS_RUNNING,
	MS_FASTRUNNING,
	MS_JUMPING,
	MS_FALLING,
	MS_COUNT
};

bool g_isCollide(Rect st, Rect nd);
////////////////////////////////////////////////////////////