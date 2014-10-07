#ifndef __CONFIG_H__
#define __CONFIG_H__

#define SCREEN_WIDTH		800
#define SCREEN_HEIGHT		600

#define FRAMERATE			60

//Get Random color
//Data type: DWORD32 (unsigned int)
#define RANDOM_COLOR		(rand() % 0xFF << 24) | (rand() % 0xFF << 16) | (rand() % 0xFF << 8) | 0xFF

#endif