#ifndef __BALL_H__
#define __BALL_H__

class CBall
{
private:
	int x;
	int y;
public:
	CBall();
	CBall(int _x, int _y);
	CBall(const CBall& ball);
};

#endif