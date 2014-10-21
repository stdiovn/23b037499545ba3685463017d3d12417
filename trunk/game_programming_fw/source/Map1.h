#ifndef _Map1_
#define _Map1_
#include"MapObject.h"


#define BackGround "data//Map_1.jpg"

class Map1 :public MapObject
{
	~Map1();
public:
	Map1();
	void InitMap(char*);
	bool NextMap();
};
#endif