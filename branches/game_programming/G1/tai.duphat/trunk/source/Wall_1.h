#ifndef _Wall_1_
#define _Wall_1_

#include"Entity.h"
#include <vector>
#define ImageWall "Data//wall-break.png"

class Wall_1
{
protected:
	std::vector<Entity*> entities;
	int m_Healthy;

	~Wall_1();
public:
	Wall_1();
	void Clear();
	int getWidth();
	int getHeight();
	void Render(Graphics *g);
	bool isActiveRender();
	void de_activeRender();
	void setPosition(int x, int y);
};

#endif