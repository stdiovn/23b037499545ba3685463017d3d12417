#ifndef __TYPE1_H__
#define __TYPE1_H__
#include "Brick.h"

using namespace stdio_fw;
class Type1 :public Brick
{
private:
	Image* m_BrickImage1;
	Image* m_BrickImage2;
public:
	Type1();
	~Type1();
	void InitBrick();
	int GetBrickX();
	int GetBrickY();
	int GetLive();
	void SetLive();
	void SetCounti(int i);
	void SetCountj(int j);
	Image* GetImage();
	void ReleaseBrick();
};

#endif