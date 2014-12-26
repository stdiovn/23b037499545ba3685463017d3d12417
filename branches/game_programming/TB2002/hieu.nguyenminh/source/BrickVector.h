#pragma once

#include "AbstractBrick.h"
#include "Ball.h"
#include <vector>
using namespace std;
using namespace stdio_fw;

class BrickVector
{
private:
	vector<AbstractBrick*> m_Vector;
public:
	BrickVector();
	virtual ~BrickVector();
	void createNormalBrickMap(unsigned int _Number_of_Bricks, Vec2 _First_Position, float _Horizontal_Distance, float _Vertial_Distance);
	int getSize();
	void CollisionBehaviorwithBall(Ball* _Ball);
	void render(Graphics *g);
};

