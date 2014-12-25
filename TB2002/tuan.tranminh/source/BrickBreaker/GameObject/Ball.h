#ifndef Ball_h__
#define Ball_h__

#include "BrickBreaker/GameObject/MoveObject.h"
#include "BrickBreaker/GameObject/ControlableObject.h"
#include "BrickBreaker/GameObject/Bat.h"
using namespace stdio_fw;

#include <time.h>

#define BALL_SIZE_WIDTH 10
#define BALL_SIZE_HEIGHT 10
#define BALL_RESOURCE	"resource//ball.png"
#define BALL_DEFAULT_SPEED	(SPEED_DEFAULT / 4.0)
#define BALL_SPEED_CAP	5

enum BallStatus
{
	ON_BAT = 0,
	FLYING,
	NUM_OF_STATUS
};

class Ball : public MoveObject, public ControlableObject
{
public:
	Ball(Bat* linkedBat);
	~Ball();

	virtual void draw(Graphics* g);

	virtual void update(float deltaTime);

	virtual bool outOfScreenHandling(Vector2 moveDistance);

	virtual void eventHandling(const map<KeyCode, KeyState>& currentKeyState);

	virtual float generateVeloXForTheBallWhenHitBat();

	virtual void hitBrick();

private:
	Image* _ballImage;
	Bat*	_linkedBat;
	BallStatus _status;
};

#endif // Ball_h__
