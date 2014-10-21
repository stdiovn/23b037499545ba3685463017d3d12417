#ifndef _MapObject_
#define _MapObject_
#include "Wall_2.h"
#include "Object.h"
#include <fstream>
#include "Ball.h"
using namespace std;

class MapObject
{
protected:
	vector<Wall_1*> FrameWall;

	vector<Object> FramePosition;

	Entity *m_BackGround;
	Entity *m_GameOver;

	int m_CountWallOnScreen;
	
	bool isActive;
	~MapObject();
public:
	MapObject();
	virtual void InitMap(char*);
	virtual void Render(Graphics*);
	int getWidth(int);
	int getHeight(int);
	int getCountFrameWallOnMap();
	bool isActiveRenderAt(int);
	void deActiveRenderAt(int);


	Object getPosition(int);

	bool isGameOver();
	void setIsActive(bool);
	virtual bool NextMap();
	virtual void Clear();
};

enum KindOfWall
{
	WallOneHit = 0,
	WallTwoHit,
};
#endif