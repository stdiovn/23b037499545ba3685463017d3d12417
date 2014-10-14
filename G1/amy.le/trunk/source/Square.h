#ifndef __SQUARE_H__
#define __SQUARE_H__

#define SRCWidth 800
#define SRCHeight 600
#define SqrWidth 50
#include "Rect.h"
#include "Brick.h"
using namespace stdio_fw;
class Square
{
private:
	int m_SqrSpeedX;
	int m_SqrSpeedY;
	int m_SqrX;
	int m_SqrY;
	bool IsConllideRect;
	bool IsConllideBrick;
	Image* m_SquareImage;
public:
	Square();
	~Square();
	void InitSquare();
	int GetSqrX();
	int GetSqrY();
	bool GetIsConllideRect();
	bool GetIsConllideBrick();
	Image* GetSquareImage();
	void ConllideSquare(Rect* R, Brick* B);
	void TransferSquare(Rect* R);
	void ReleaseSquare();
};

#endif
