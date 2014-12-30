#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "BaseObject.h"

using namespace stdio_fw;
class Mushroom : public BaseObject
{
public:
	Mushroom(Image* spritesheet, std::vector<Frame>* frameList)
		: BaseObject(spritesheet, frameList){}
	~Mushroom(){}

	void		update(){}
	void		render(Graphics* g){}
};