#ifndef Brick_Breaker_Macros_h__
#define Brick_Breaker_Macros_h__

#include "BrickBreaker/Core/Vector2.h"

#define SCREEN_SIZE_WIDTH	400
#define SCREEN_SIZE_HEIGHT	500

#define COLOR_TRANSPARENT	0x00000000

#define SPEED_NO	(Vector2(0.0f, 0.0f))
#define SPEED_DEFAULT		10

#define CONTROL_MOVE_LEFT	KEY_A
#define CONTROL_MOVE_RIGHT	KEY_D
#define CONTROL_A			KEY_J
#define CONTROL_B			KEY_K
#define NUM_OF_CONTROL_KEY	4

#define FOR(A)		for(int i = 0; i < A; ++i)
#define FOR_t(A)	for(size_t i = 0; i < A; ++i)

#define MICROSEC_TO_SEC(microsec)	(microsec / 1000.0)

#endif // Macros_h__
