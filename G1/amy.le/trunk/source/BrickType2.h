#ifndef __TYPE2_H__
#define __TYPE2_H__
using namespace stdio_fw;
#include "Brick.h"
class Type2:public Brick
{
private:
	Image* m_BrickImage3;
public:
	Type2();
	~Type2();
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