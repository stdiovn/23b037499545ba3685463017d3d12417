#ifndef __RECT_H__
#define __RECT_H__

#define RectWidth 200
#define  RectHeight 63
using namespace stdio_fw;
class Rect
{
private:
	int m_RectSpeedX;
	int m_RectX;
	int m_RectY;
	Image* m_RectImage;
public:
	Rect();
	~Rect();
	void InitRect();
	int GetRectX();
	int GetRectY();
	Image* GetRectImage();
	void ConllideRect();
	void TransferRect(KeyState KeyRight, KeyState KeyLeft);
	void ReleaseRect();
};

#endif
