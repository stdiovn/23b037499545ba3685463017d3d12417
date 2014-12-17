#pragma once
#include "Brick.h"
class CStone :
	public CBrick
{
public:
	CStone();
	CStone(const char* filePath, const char* filePath2, s_vector2D position);
	~CStone();

	virtual ErrorCode	Init()					override;
	virtual void		Update(float deltaTime) override;
	virtual void		Render(Graphics* g)		override;
	virtual void		Release()				override;
};

