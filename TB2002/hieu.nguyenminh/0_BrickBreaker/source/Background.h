#pragma once

#include "StaticObject.h"

using namespace stdio_fw;


class Background :
	public StaticObject
{
protected:
	Image** m_Image;
public:
	Background();
	virtual ~Background();
	Background(Image *_image_Backgound);
	virtual void update(float deltaTime) override;
	virtual void render(Graphics *g) override;
};

