#ifndef Bat_h__
#define Bat_h__

#include "BrickBreaker/GameObject/MoveObject.h"
#include "BrickBreaker/Core/BBMacros.h"
#include "BrickBreaker/Core/KeyBuffer.h"

#define DEFAULT_BAT_WIDTH		80
#define DEFAULT_BAT_HEIGHT		15

#define DEFAULT_BAT_MOVESPEED	SPEED_DEFAULT
#define DEFAULT_BAT_COLOR		0x00FF00FF

#define DEFAULT_START_POINT	Vector2((int)((SCREEN_SIZE_WIDTH - DEFAULT_BAT_WIDTH) / 2.0), (int)(SCREEN_SIZE_HEIGHT - DEFAULT_BAT_HEIGHT) - 10)
#define DEFAULT_LIFE_NUM	3

class Bat : public MoveObject, public ControlableObject
{
public:
				 Bat();
	virtual		 ~Bat();

	virtual void draw(Graphics* g);
	virtual void update(float deltaTime);
	virtual bool outOfScreenHandling(Vector2 moveDistance);
			void broken();
			bool ifLoose();

	virtual void eventHandling(const map<KeyCode, KeyState>& currentKeyState);

private:
	int _lifeRemaining;
};

#endif // Ball_h__
