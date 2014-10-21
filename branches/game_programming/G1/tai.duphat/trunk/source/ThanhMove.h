#pragma once
#include "Entity.h"
#define MoveImage "data//ThanhMove.png"

class ThanhMove
{
	Entity *m_Move;

	int m_Y;
	~ThanhMove();
public:
	ThanhMove(int x, int y);
	void UpdateCollisionWithWindows(int, int);
	void UpdateSpeedKeyBoard(KeyCode);
	int getWidth();
	int getHeight();
	int getPositionX();
	int getPositionY();
	void Render(Graphics*);
	void Clear();
};

