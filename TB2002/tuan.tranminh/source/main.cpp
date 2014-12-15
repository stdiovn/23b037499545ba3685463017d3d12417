#include "stdafx.h"
#include "Game.h"

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.Init(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, "Brick Breaker");

	g.Run();
}