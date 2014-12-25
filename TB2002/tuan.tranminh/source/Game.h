#ifndef Game_h__
#define Game_h__

#include "BrickBreaker/GameObject/Bat.h"
#include "BrickBreaker/GameObject/Ball.h"
#include "BrickBreaker/Core/KeyBuffer.h"
#include "BrickBreaker/Core/Default.h"
#include "BrickBreaker/Manager/BrickMap.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <vector>

using namespace stdio_fw;

class Game : public Application
{
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();

private:
	Bat* _bat;
	vector<Ball*> _balls;
	Image* temp;
	int _ballRemaining;
};

#endif // Game_h__