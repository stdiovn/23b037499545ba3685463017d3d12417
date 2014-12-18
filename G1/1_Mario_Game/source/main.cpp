#include "stdafx.h"
#include "Game.h"

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");

	g.Run();
}