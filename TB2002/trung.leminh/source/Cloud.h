#ifndef __C_CLOUD_H__
#define __C_CLOUD_H__

#include "Objects.h"
class CCloud :
	public CObjects
{
public:
	CCloud();
	~CCloud();
	CCloud(int positionX, int positionY, int velocityX, int velocityY);
	virtual ErrorCode	Init()				override;
	virtual void		Update(float deltaTime)			override;
	virtual void		UpdateEventHandle() override;	// Update event of device( Keyboard, mouse ... )
	virtual void		Render(Graphics* g)	override;
	virtual void		Release()			override;

protected:

};

#endif