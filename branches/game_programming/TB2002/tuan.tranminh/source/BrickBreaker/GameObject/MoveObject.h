#ifndef MoveObject_h__
#define MoveObject_h__

#include "BrickBreaker/GameObject/Object.h"
#include "BrickBreaker/GameObject/ControlableObject.h"
#include "BrickBreaker/Core/BBMacros.h"

#define SPEED_TO_RIGHT(absolute_Velocity)	(absolute_Velocity)
#define SPEED_TO_LEFT(absolute_Velocity)	(-absolute_Velocity)
#define SPEED_TO_TOP(absolute_Velocity)		(-absolute_Velocity)
#define SPEED_TO_BOTTOM(absolute_Velocity)	(absolute_Velocity)

class MoveObject : public Object
{
public:
	virtual				~MoveObject();

	virtual void		draw(Graphics* g)			= 0;
	virtual void		update(float deltaTime);
	virtual bool		outOfScreenHandling(Vector2 moveDistance) = 0;

			
			Vector2		getVelocity();
			void		moveHorizontal(float velocity);
			void		moveVertical(float velocity);
			void		move(float X_AxisVelo, float Y_AxisVelo);
			void		move(Vector2 velocity);
			
	virtual bool		checkIfBoundWith(Rect objRect);
			Vector2&	getPosition();
			Rect		getDefRect();

			void		setMoveObjectProperties(const Vector2& position, float width, float height, Vector2 velocity);
private:
	Vector2*	_velocity;
	Vector2*	_position;
	Rect*		_defRect;

};
#endif // MoveObject_h__
