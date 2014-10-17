#pragma once
#include "ObjectMap.h"
#include <vector>
#include <fstream>
#include "Wall_2.h"
using namespace std;
class BackGround
{
	Wall_1 *m_Wall;
	Wall_2 *m_Wall2;

	vector<ObjectMap> m_FrameOnject;
	int m_Size;
public:
	BackGround();
	Image* GetImage(int );
	bool IsCollision(Rect);
	virtual ~BackGround();
};

