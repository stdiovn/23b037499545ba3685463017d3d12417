#ifndef ControlableObject_h__
#define ControlableObject_h__

#include <map>
using namespace std;

class ControlableObject
{
public:
	virtual void eventHandling(const map<KeyCode, KeyState>& currentKeyState) = 0;
};

#endif // ControlableObject_h__
