#include "stdafx.h"
#include "BrickVector.h"
#include "AbstractBrick.h"
#include "NormalBrick.h"
#include "ImmortalBrick.h"
#include "ExplosiveBrick.h"


BrickVector::BrickVector()
{
}


BrickVector::~BrickVector()
{
}


void BrickVector::createNormalBrickMap(unsigned int _Number_of_Bricks, Vec2 _First_Position, float _Horizontal_Distance, float _Vertial_Distance)
{
	AbstractBrick* _Temp_Brick;
	_Temp_Brick = new NormalBrick(_First_Position);
	float _Brick_Width = _Temp_Brick->getBound().width;
	float _Brick_Height = _Temp_Brick->getBound().height;
	int _num_of_brick_in_a_row = (800 - _First_Position.x) / (_Brick_Width + _Horizontal_Distance);

	m_Vector.push_back(_Temp_Brick);
	Vec2 _Temp_Postion = _First_Position + Vec2(_Brick_Width + _Horizontal_Distance, 0);

	for (int i = 1; i < _Number_of_Bricks; i++)
	{
		_Temp_Brick = new NormalBrick(_Temp_Postion);
		m_Vector.push_back(_Temp_Brick);
		if (m_Vector.size() % _num_of_brick_in_a_row == 0)
		{
			_Temp_Postion.x = _First_Position.x;
			_Temp_Postion.y = _Temp_Postion.y + _Brick_Height + _Vertial_Distance;
		}
		else
		{
			_Temp_Postion.x += _Brick_Width + _Horizontal_Distance;
		}
	}

}


int BrickVector::getSize()
{
	return m_Vector.size();
}


void BrickVector::CollisionBehaviorwithBall(Ball* _Ball)
{
	for (int i = 0; i < m_Vector.size(); i++)
	{
		_Ball->CollisionBehavior(m_Vector[i]);
		if (m_Vector[i]->isDead())
		{
			m_Vector.erase(m_Vector.begin() + i);
		}
	}
}


void BrickVector::render(Graphics *g)
{
	for (int i = 0; i < m_Vector.size(); i++)
	{
		m_Vector[i]->render(g);
	}
}