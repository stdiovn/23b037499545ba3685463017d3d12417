//------------------------begin abstract object class----------//
#ifndef __ABSTRACT_OBJECT_H__
#define	__ABSTRACT_OBJECT_H__
#include "STDIO_FW\stdio_fw.h"

using namespace stdio_fw;
class CAbstractObject
{
public:
	CAbstractObject();
	~CAbstractObject();

	virtual ErrorCode	Init()					= 0;
	virtual void		Update(float deltaTime)	= 0;
	virtual void		Render(Graphics* g)		= 0;
	virtual void		Release()				= 0;
};

#endif
//-------------------------end abstract object class-----------//