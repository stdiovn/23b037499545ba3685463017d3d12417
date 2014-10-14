#ifndef __BRICK_H__
#define __BRICK_H__
using namespace stdio_fw;
#define BrickWidth 60
#define BrickHeight 90

enum BrickType
{
	BrickType1,
	BrickType2
};

class Brick
{
protected:
	int m_BrickX;
	int m_BrickY;
	int m_Counti = 0;
	int m_Countj = 0;
	int m_Live;
public:
	Brick();
	~Brick();
	virtual void InitBrick() = 0;
	virtual int GetBrickX() = 0;
	virtual int GetBrickY() = 0;
	virtual int GetLive() = 0;
	virtual void SetLive() = 0;
	virtual void SetCounti(int i) = 0;
	virtual void SetCountj(int j) = 0;
	virtual Image* GetImage() = 0;
	virtual void ReleaseBrick() = 0;
};
#endif