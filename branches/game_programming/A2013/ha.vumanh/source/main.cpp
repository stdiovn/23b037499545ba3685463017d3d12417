#include "stdafx.h"
#include "Game.h"

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.Init(950, 650, "Brick Breaker Demo");

	g.Run();
}