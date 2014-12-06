#ifndef __C_SUN_H__
#define __C_SUN_H__

#include "Objects.h"
#include "SuperMan.h"

class CMapManager;

class CSun :
	public CObjects
{
public:
	CSun();
	~CSun();
			void		UpdateCollision(CMapManager* mapManager, CSuperMan* superMan);
	virtual ErrorCode	Init()							override;
	virtual void		Update(float deltaTime)			override;
	virtual void		UpdateEventHandle()				override;	// Update event of device( Keyboard, mouse ... )
	virtual void		Render(Graphics* g)				override;
	virtual void		Release()						override;
			
private:

};

#include "MapManager.h"
#endif