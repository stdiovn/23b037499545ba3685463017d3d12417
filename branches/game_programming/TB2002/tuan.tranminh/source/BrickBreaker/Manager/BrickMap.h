#ifndef BrickMap_h__
#define BrickMap_h__

#include <vector>
#include <fstream>

#include "BrickBreaker/Core/Default.h"

#include "BrickBreaker/GameObject/NormalBrick.h"
#include "BrickBreaker/GameObject/ImmortalBrick.h"

#define MAP_FILE_EXTENSION		".txt"
#define LINK_MAPS				"resource//Maps//"
#define GET_LINK_STAGE(stage)	(string(LINK_MAPS) + Default::tostr(stage) + string(MAP_FILE_EXTENSION))
#define NUM_OF_BRICK_PER_ROW	(int)(SCREEN_SIZE_WIDTH / BRICK_SIZE_WIDTH)

class BrickMap
{
public:
	static void load(int stage);

	static int checkIfTouchBrick(Rect boundRange);

	static void draw(Graphics* g);
	static void update(float deltaTime);

private:
	BrickMap();
	~BrickMap();

	static Vector2 computePosition(int index);

	static BrickMap& getInstance();

private:
	vector<Brick*> _bricks;
	static BrickMap* _instance;
};

#endif // BrickMap_h__
