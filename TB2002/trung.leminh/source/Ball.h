#ifndef __BALL_H__
#define __BALL_H__
#include "MoveableObject.h"
#include "CommonStructure.h"
#include "Bar.h"

class CMapmanager;

class CBall :
	public CMoveableObject
{
public:
	CBall();
	~CBall();
	CBall(const char* filePath, s_vector2D position);

	virtual ErrorCode	Init()					override;
	virtual void		Update(float deltaTime) override;
	void		UpdateInputHandle(float deltaTime);
	virtual void		Render(Graphics* g)		override;
	virtual void		Release()				override;
			e_StateBall getNameStateBall(const char* filePath);
			void		UpdateCollisionWithAllthingInMap(CBar* Bar, CMapmanager* map);

protected:

	e_StateBall			m_stateBall;
};

#include "Mapmanager.h"
#endif
