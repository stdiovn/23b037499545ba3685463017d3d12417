#ifndef __C_SUPERMAN_H__
#define __C_SUPERMAN_H__
#include "Objects.h"
#include "CommonStructure.h"	
class CSuperMan :
	public CObjects
{
public:
	CSuperMan();
	~CSuperMan();
	virtual ErrorCode	Init()							override;
	virtual void		Update(float deltaTime)			override;
	virtual void		UpdateEventHandle()				override;	// Update event of device( Keyboard, mouse ... )
	virtual void		Render(Graphics* g)				override;
	virtual void		Release()						override;

			int			getPosY();
protected:

};

#endif