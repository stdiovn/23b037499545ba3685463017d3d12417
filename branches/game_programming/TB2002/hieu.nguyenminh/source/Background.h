#pragma once
#include "StaticObject.h"
class Background :
	public StaticObject
{
protected:
	Image** mImage;
public:
	Background();
	Background(Image *_image_Backgound);
	virtual void Update();
	virtual void Render(Graphics *g);
	virtual ~Background();
};

