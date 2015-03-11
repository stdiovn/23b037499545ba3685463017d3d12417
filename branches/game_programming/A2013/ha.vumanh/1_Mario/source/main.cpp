#include "stdafx.h"
#include "Game.h"

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
void main()
{
	Game g;
	g.init(1024, 512, "Mario Game - The Second Failure");

	g.run();
}