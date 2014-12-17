#pragma once
#include "MoveableObject.h"
#include "CommonStructure.h"
#include <string>

using namespace std;
class CBar :
	public CMoveableObject
{
public:
	CBar();
	~CBar();
	CBar(const char* filePath, s_vector2D position);

	virtual ErrorCode	 Init()						override;
	virtual void		 Update(float deltaTime)	override;
			void		 UpdateInputHandle(float deltaTime);
	virtual void		 Render(Graphics* g)		override;
	virtual void		 Release()					override;
			e_KindOfBall getNameKindOfBall(const char* filePath);
			
			int			 getPosY();
protected:

	e_Direction			m_direction;
	e_KindOfBall		m_kindOfBall;
};

