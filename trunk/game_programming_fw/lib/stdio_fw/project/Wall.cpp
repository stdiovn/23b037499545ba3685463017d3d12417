#include "Wall.h"


Sprite::Sprite(int Left, int Right, int Top, int Bottom)
{
	this->Left = Left;
	this->Right = Right;
	this->Top = Top;
	this->Bottom = Bottom;

	IsDraw = true;
	veclocity = 3;
}


void Sprite::DiChuyen()
{
	
}

bool Sprite::IsPact(Sprite sprite)
{
	// va cham voi 4 canh cua so
	if (Left < 0 || Right > SCREEN_WIDTH || Top < 0 || Bottom > SCREEN_HEIGHT) return true;

	// va cham voi object

	int TamI1_X = abs(Left - Right) / 2;
	int TamI1_Y = abs(Top - Bottom) / 2;

	int TamI2_X = abs(sprite.Left - sprite.Right) / 2;
	int TamI2_Y = abs(sprite.Top - sprite.Bottom) / 2;

	if (abs(TamI1_X - TamI2_X) < (Right - Left + sprite.Right - sprite.Left) / 2
		&& abs(TamI2_Y - TamI1_Y) < (Bottom - Top + sprite.Bottom - sprite.Top) / 2) return true;

	return false;
}

Sprite::~Sprite()
{
}
