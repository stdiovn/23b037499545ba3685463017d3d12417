#pragma once

using namespace stdio_fw;
struct Frame
{
	std::string		m_id;
	Rect			m_frameRect;
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

bool g_isCollide(Rect st, Rect nd);