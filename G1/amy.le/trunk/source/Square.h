#ifndef __SQUARE_H__
#define __SQUARE_H__

#define SRCWidth 800
#define SRCHeight 600
#define SqrWidth 50
#include "Rect.h"

using namespace stdio_fw;
class Square
{
private:
	int m_SqrSpeedX;
	int m_SqrSpeedY;
	int m_SqrX;
	int m_SqrY;
	Image* m_SquareImage;
public:
	Square();
	~Square();
	void InitSquare();
	int GetSqrX();
	int GetSqrY();
	Image* GetSquareImage();
	void ConllideSquare();
	void TransferSquare(Rect* R);
	void ReleaseSquare();
};

#endif
