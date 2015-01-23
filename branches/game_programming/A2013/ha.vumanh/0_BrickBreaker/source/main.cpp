#include "stdafx.h"
#include "Game.h"

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.init(1100, 600, "Brick Breaker Demo");
	g.run();
}