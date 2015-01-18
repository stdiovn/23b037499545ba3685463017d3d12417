#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__
#include "CommonStructure.h"
class CInputManager
{
public:
	CInputManager();	
	~CInputManager();
		
	void Init();
	void Update(float);
	void Render();
	void Release();
};
#endif
