#pragma once

#define SCREEN_WIDTH			800
#define SCREEN_HEIGHT			600
#define FRAME_RATE				30

//////////////////////////////////////////
//PLATFORM
#define WINDOWS					0
#define LINUX					1
#define MACOS					2
#define PLATFORM				WINDOWS

#define CREATE_MUSHROOM			Factory::GetInstance()->CreateMushroom()
#define MUSHROOM_PATH			"image//mushroom//kolobok_01_walk_00xx.png"
#define MUSHROOM_FRAME_COUNT	12

#define MAP_PATH				"map//mapx.rye"
#define DEFAULT_TILE_WIDTH		20
#define DEFAULT_TILE_HEIGHT		20


#define CHAR(x)					x + 48
#define INT(x)					x - 48