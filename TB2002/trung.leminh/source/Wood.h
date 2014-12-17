#pragma once
#include "Brick.h"
class CWood :
	public CBrick
{
public:
	CWood();
	CWood(const char* filePath, s_vector2D position);
	~CWood();

	virtual ErrorCode	Init()					override;
	virtual void		Update(float deltaTime) override;
	virtual void		Render(Graphics* g)		override;
	virtual void		Release()				override;
};

