#ifndef _Map2_
#define _Map2_
#include"MapObject.h"

#define BackGround "Data//Map_2.jpg"

class Map2 :public MapObject
{
	~Map2();
public:
	Map2();
	void InitMap(char*);
	void Clear();
};
#endif