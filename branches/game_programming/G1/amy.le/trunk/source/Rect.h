#pragma once
#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
using namespace stdio_fw;
class Rect
{
private:
	int m_X;
	int m_Y;
	int m_SpeedX;
	int m_SpeedY;
	int m_Width;
	int m_Height;
	int m_IsCollideRect;
public:
	Rect();
	void Init(int x, int y, int speedx, int speedy, int width, int height);
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	int GetSpeedX();
	int GetSpeedY();
	int GetIsCollide();
	void SetSpeedX(int speedx);
	void SetSpeedY(int speedy);
	void TransferOfControlledRect(KeyState KeyLeft, KeyState KeyRight);
	void TransferOfAutoRect();
	void CollideWithRect(Rect* R);
	void Release();
	~Rect();
};

