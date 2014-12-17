#pragma once
#include "StaticObject.h"
#include <string>
class CBackgrounds :
	public CStaticObject
{
public:
	CBackgrounds();
	CBackgrounds(const char* filePath, int posX,int posY);
	~CBackgrounds();
	virtual ErrorCode	Init()							override;
	virtual void		Update(float deltaTime)			override;
	virtual void		Render(Graphics* g)				override;
	virtual void		Release()						override;

};

