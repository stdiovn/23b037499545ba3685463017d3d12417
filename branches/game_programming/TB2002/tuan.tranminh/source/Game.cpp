#include "stdafx.h"
#include "Game.h"
using namespace stdio_fw;
using namespace std;

Game::Game()
{
	_ballRemaining = 3;
}

Game::~Game()
{
}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);	
	if (errCode == ErrorCode::ERR_NO_ERROR)
	{
		_bat = new Bat();
		_balls.push_back(new Ball(_bat));
		BrickMap::load(1);
	}
	return errCode;
}

void Game::Update(float deltaTime)
{
	if (_balls.size() > 0)
	{
		KeyBuffer::update((Application*)this, Default::_controlKeysArray);

		BrickMap::update(deltaTime);

		FOR_t(_balls.size())
		{
			_balls.at(i)->eventHandling(KeyBuffer::getCurrentKeyStates());
			_balls.at(i)->update(deltaTime);

			if (BrickMap::checkIfTouchBrick(_balls.at(i)->getDefRect()) != BRICK_NONE)
				_balls.at(i)->hitBrick();

			if (_balls.at(i)->getDefRect().y > SCREEN_SIZE_HEIGHT)
			{
				SAFE_DEL(_balls.at(i));
				_balls.erase(_balls.begin() + i);
				i--;

				if (_ballRemaining > 0)
				{
					_balls.push_back(new Ball(_bat));
					_ballRemaining--;
				}
			}
		}
		_bat->eventHandling(KeyBuffer::getCurrentKeyStates());
		_bat->update(deltaTime);
	}
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();
	g->setColor(0xFF0000F0);

	FOR(_ballRemaining)
		g->fillRect(Rect(1 + i * 7, SCREEN_SIZE_HEIGHT - 13, 6, 12));

	_bat->draw(g);
	BrickMap::draw(g);
	FOR_t(_balls.size())
		_balls.at(i)->draw(g);
	
	
}

void Game::Exit()
{
	SAFE_DEL(_bat);
	FOR_t(_balls.size())
		SAFE_DEL(_balls.at(i));

}