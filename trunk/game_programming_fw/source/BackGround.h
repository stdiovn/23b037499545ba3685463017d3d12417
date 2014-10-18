#pragma once
#include "ObjectMap.h"
#include <vector>
#include <fstream>
#include "Wall_2.h"
#include "Global.h"
using namespace std;
class BackGround
{
protected:
	vector<Wall_1*> m_FrameWall;
	int m_Size;
public:
	BackGround();
	BackGround(char *PathOfFileMap);

	bool *m_isDraw;
	Image *m_BackGround;
	vector<ObjectMap> m_FrameOnject;
	
	void GetCoutOfWallOnScreen();
	Wall_1* GetWall(int index);

	bool NextBackGround();
	
	void Update();
	virtual ~BackGround();
};

