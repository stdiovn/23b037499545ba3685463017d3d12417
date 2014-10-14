#ifndef __CONFIG_H__
#define __CONFIG_H__

#define SCREEN_WIDTH		800
#define SCREEN_HEIGHT		600

#define FRAMERATE			60


//Define Flatform is using.
#define PLATFORM			WINDOWS

#define WINDOWS				0
#define LINUS				1
#define MACOS				2



//Get Random color
//Data type: DWORD32 (unsigned int)
#define RANDOM_COLOR		(rand() % 0xFF << 24) | (rand() % 0xFF << 16) | (rand() % 0xFF << 8) | 0xFF

#define IS_SUPER_BRICK		rand() % 4

#define MAX_LEVEL			2

#endif