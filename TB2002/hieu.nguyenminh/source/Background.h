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
	Background(Image *_image_Backgound);
	virtual void Update(float deltaTime) override;
	virtual void Render(Graphics *g) override;
	virtual ~Background();
};

