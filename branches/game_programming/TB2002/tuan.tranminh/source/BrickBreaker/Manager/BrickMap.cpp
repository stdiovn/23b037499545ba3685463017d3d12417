#include "stdafx.h"
#include "BrickBreaker/Manager/BrickMap.h"


BrickMap* BrickMap::_instance = nullptr;


BrickMap::BrickMap()
{
}


BrickMap::~BrickMap()
{
	FOR_t(getInstance()._bricks.size())
		SAFE_DEL(getInstance()._bricks.at(i));
	getInstance()._bricks.clear();
}


void BrickMap::load(int stage)
{
	fstream data(GET_LINK_STAGE(stage).c_str());
	if (data.is_open())
	{
		while (!data.eof())
		{
			int brickType, index;
			data >> brickType >> index;

			switch (brickType)
			{
			case BRICK_NORMAL:
				int healthPoints;
				data >> healthPoints;

				getInstance()._bricks.push_back(new NormalBrick(computePosition(index), healthPoints));
				break;

			case BRICK_IMMORTAL:
				getInstance()._bricks.push_back(new ImmortalBrick(computePosition(index)));
				break;

			case BRICK_EXPLODE:
				//UPDATE
				break;

			default:
				break;
			}
		}
	}
}


int BrickMap::checkIfTouchBrick(Rect boundRange)
{
	FOR_t(getInstance()._bricks.size())
		if (getInstance()._bricks.at(i)->checkIfBoundWith(boundRange))
		{
			Brick* touchedOne = getInstance()._bricks.at(i);
			if (touchedOne->damaged() == BRICK_DESTROYED)
				getInstance()._bricks.erase(getInstance()._bricks.begin() + i);

			//UPDATE
			return BRICK_NORMAL;
		}

	return BRICK_NONE;
}


Vector2 BrickMap::computePosition(int index)
{
	Vector2 result;
	result.x = (float)(index % NUM_OF_BRICK_PER_ROW * BRICK_SIZE_WIDTH);
	result.y = (float)(index / NUM_OF_BRICK_PER_ROW * BRICK_SIZE_HEIGHT);

	return result;
}


BrickMap& BrickMap::getInstance()
{
	if (BrickMap::_instance == nullptr)
	{
		BrickMap::_instance = new BrickMap();
	}

	return *BrickMap::_instance;
}


void BrickMap::draw(Graphics* g)
{
	FOR_t(getInstance()._bricks.size())
		getInstance()._bricks.at(i)->draw(g);
}


void BrickMap::update(float deltaTime)
{
	FOR_t(getInstance()._bricks.size())
		getInstance()._bricks.at(i)->update(deltaTime);
}
