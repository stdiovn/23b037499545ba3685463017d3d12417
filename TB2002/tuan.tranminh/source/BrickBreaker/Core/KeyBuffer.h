#ifndef KeyBuffer_h__
#define KeyBuffer_h__

#include "stdafx.h"
#include "Application.h"

#include <map>
#include "BBMacros.h"
using namespace stdio_fw;
using namespace std;

class KeyBuffer
{
public:
	static void initializeKeyBuffer(int nControlKeys);
	static void update(Application* app, KeyCode* virtualKeyArray);

	static KeyState getKeyState(KeyCode virtualKeyCode);
	static KeyState getPreviousKeyState(KeyCode virtualKeyCode);
	static map<KeyCode, KeyState> getCurrentKeyStates();

private:
	KeyBuffer(int nControlKeys);
	~KeyBuffer();

	static KeyBuffer& getInstance(int nControlKey = NUM_OF_CONTROL_KEY);

private:
	static KeyBuffer* _instance;
	int	_size;

	map<KeyCode, KeyState> _previousBuffer;
	map<KeyCode, KeyState> _currentBuffer;
};

#endif // KeyBuffer_h__