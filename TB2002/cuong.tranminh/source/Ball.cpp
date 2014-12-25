#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
	dBall = ES;
	rDynamicObject.x = 460;
	rDynamicObject.y = 600 - 60;
}


Ball::~Ball()
{
	
}

void Ball::Init()
{
	im = new Image(BALL);
	im->loadImage();
	//rDynamicObject.x = 35; rDynamicObject.y = 100;
	rDynamicObject.height = rDynamicObject.width = 25;
}
//void Ball::Update()
//{
//	Sleep(1);
//	if (isRight == NULL && isUP == NULL)
//	{
//		isRight = false; isUP = true;
//		rDynamicObject.x--;
//		rDynamicObject.y++;
//	}
//	//Bóng hướng lên
//	if (isUP)
//	{
//		if (isRight)
//		{
//			
//			if (rDynamicObject.y == 0)
//			{
//				isUP = false;
//				isRight = true;
//				rDynamicObject.x++;
//				rDynamicObject.y++;
//				return;
//			}
//			if (rDynamicObject.x == 800 - 25)
//			{
//				isUP = true;
//				isRight = false;
//				rDynamicObject.y--;
//				rDynamicObject.x--;
//				return;
//			}
//			rDynamicObject.x++;
//		}
//		if (!isRight)
//		{
//			
//			if (rDynamicObject.x == 0)
//			{
//				isUP = isRight = true;
//				rDynamicObject.x++;
//				rDynamicObject.y--;
//				return;
//			}
//			if (rDynamicObject.y == 0)
//			{
//				isUP = isRight = false;
//				rDynamicObject.x--;
//				rDynamicObject.y++;
//				return;
//			}
//			rDynamicObject.x--;
//		}
//
//		rDynamicObject.y--;
//	}
//
//	//Bóng hướng xuống
//	if (!isUP)
//	{
//		
//		if (isRight)
//		{
//			
//			if (rDynamicObject.x == 800 - 25)
//			{
//				isUP = isRight = false;
//				rDynamicObject.x--;
//				rDynamicObject.y++;
//				return;
//			}
//			if (rDynamicObject.y == 600 - 25)
//			{
//				isRight = isUP = true;
//
//				rDynamicObject.x++;
//				rDynamicObject.y--;
//				return;
//			}
//			rDynamicObject.x++;
//		}
//		if (!isRight)
//		{
//			
//			if (rDynamicObject.x == 0)
//			{
//				isRight = true;
//				isUP = false;
//				rDynamicObject.x++;
//				rDynamicObject.y++;
//				return;
//			}
//			if (rDynamicObject.y == 600 - 25)
//			{
//				isUP = true;
//				isRight = false;
//				rDynamicObject.x--;
//				rDynamicObject.y--;
//				return;
//			}
//			rDynamicObject.x--;
//		}
//		rDynamicObject.y++;
//	}
//	
//}
void Ball::Render(Graphics* g)
{
	g->drawImage(im, rDynamicObject, 0);
}

void Ball::Update()
{
	Sleep(1);
	if (dBall == ES)
	{
		if (rDynamicObject.x == 775)
		{
			dBall = WS;
			rDynamicObject.x--;
			rDynamicObject.y++;
			return;
		}
		if (rDynamicObject.y == 575)
		{
			dBall = EN;
			rDynamicObject.y--;
			rDynamicObject.x++;
			return;
		}
		rDynamicObject.x++;
		rDynamicObject.y++;
	}
	if (dBall == EN)
	{
		if (rDynamicObject.y == 0)
		{
			dBall = ES;
			rDynamicObject.x++;
			rDynamicObject.y++;
			return;
		}
		if (rDynamicObject.x == 775)
		{
			dBall = WN;
			rDynamicObject.x--;
			rDynamicObject.y--;
			return;
		}
		rDynamicObject.x++;
		rDynamicObject.y--;
	}
	if (dBall == WN)
	{
		if (rDynamicObject.x == 0)
		{
			dBall = EN;
			rDynamicObject.x++;
			rDynamicObject.y--;
			return;
		}

		if (rDynamicObject.y == 0)
		{
			dBall = WS;
			rDynamicObject.x--;
			rDynamicObject.y++;
			return;
		}
		rDynamicObject.x--;
		rDynamicObject.y--;
	}
	if (dBall == WS)
	{
		if (rDynamicObject.x == 0)
		{
			dBall = ES;
			rDynamicObject.x++;
			rDynamicObject.y++;
			return;
		}
		if (rDynamicObject.y == 575)
		{
			dBall = WN;
			rDynamicObject.x--;
			rDynamicObject.y--;
		}
		rDynamicObject.x--;
		rDynamicObject.y++;
	}
}
void Ball::setDirection(DIRECTION d)
{
	dBall = d;
}

DIRECTION Ball::getDirection()
{
	if (dBall == ES)
	{
		dBall = EN;
		return dBall;
	}
	if (dBall == WS)
	{
		dBall = WN;
		return dBall;
	}
	if (dBall == EN)
	{
		dBall = ES;
		return dBall;
	}
	if (dBall == WN)
	{
		dBall = WS;
		return dBall;
	}

}