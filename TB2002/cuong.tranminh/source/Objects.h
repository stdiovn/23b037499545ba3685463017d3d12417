#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Ball.h"
#include "Bar.h"
#include "Brick.h"
#include <fstream>
#include <ostream>
#include <vector>
#include <list>
using namespace std;

//collision detected
 static bool Collision(Rect& rect1, Rect& rect2)
{
	if (rect1.x < rect2.x + rect2.width &&
		rect1.x + rect1.width > rect2.x &&
		rect1.y < rect2.y + rect2.height &&
		rect1.height + rect1.y > rect2.y) return true;
	return false;
}

 static void inputArr(vector<Brick>& a)
 {
	 /*float temp;
	 ifstream in("map1.inp");
	 if (!in.is_open())return;
	 while (!in.eof())
	 {
		 in >> temp;
		 Brick index(temp);
		 a.push_back(index);
	 }
	 in.close();*/


	 Brick b1(50), b2(200), b3(350), b4(500), b5(650);
	 a.push_back(b1);
	 a.push_back(b2);
	 a.push_back(b3);
	 a.push_back(b4);
	 a.push_back(b5);

 }


#endif