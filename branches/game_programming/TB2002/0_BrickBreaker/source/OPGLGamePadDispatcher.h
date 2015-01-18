//---------------------Gamepad for Stk-701-------------//
//---------------------Mr. Michael Le----------------------//

#ifndef __OPGL_GAMEPAD_DISPATCHER_H__
#define __OPGL_GAMEPAD_DISPATCHER_H__
#include "OPGLAbstractDispatcher.h"
#include "CommonStructure.h"
#include <map>

using	namespace std;

class COPGLGamePadDispatcher :
	public COPGLAbstractDispatcher
{
public:
	COPGLGamePadDispatcher();
	~COPGLGamePadDispatcher();

	virtual void Init()			override;
	virtual void Update(float)	override;
	virtual void Release()		override;

	virtual void AddEvent()		override;
	virtual void RemoveEvent()	override;
protected:
	std::map<char*, EStateKey> m_listButton;
};

#endif