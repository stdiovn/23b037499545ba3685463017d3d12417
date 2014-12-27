#pragma once

using namespace stdio_fw;

enum Components
{
	COM_TRANSFORM,
	COM_BOX_COLLIDER_2D,
	COM_RENDERER,
	COM_ANIMATION,
	COM_GUN,
	COM_MOVE,
	COM_JUMP,
	COM_COUNT
};

enum GameState
{
	STATE_PLAY,
	STATE_WIN,
	STATE_GAME_OVER,
	STATE_COUNT
};

bool isCollide(Rect st, Rect nd);