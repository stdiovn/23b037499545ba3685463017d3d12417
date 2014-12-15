#include "stdafx.h"
#include "KeyBuffer.h"


KeyBuffer* KeyBuffer::_instance = nullptr;

void KeyBuffer::update(Application* app, KeyCode* virtualKeyArray)
{
	getInstance()._previousBuffer.clear();
	getInstance()._previousBuffer = getInstance()._currentBuffer;

	getInstance()._currentBuffer.clear();
	FOR(getInstance()._size)
	{
		getInstance()._currentBuffer.insert(
			pair<KeyCode, KeyState>(virtualKeyArray[i], app->getKeyState(virtualKeyArray[i])));
	}
}

KeyBuffer& KeyBuffer::getInstance(int nControlKey)
{
	if (_instance == nullptr)
		_instance = new KeyBuffer(nControlKey);

	return *_instance;
}

KeyBuffer::~KeyBuffer()
{
	_previousBuffer.clear();
	_currentBuffer.clear();
}

KeyBuffer::KeyBuffer(int nControlKeys)
{
	_size = nControlKeys;
}

map<KeyCode, KeyState> KeyBuffer::getCurrentKeyStates()
{
	return getInstance()._currentBuffer;
}

stdio_fw::KeyState KeyBuffer::getPreviousKeyState(KeyCode virtualKeyCode)
{
	return getInstance()._previousBuffer.at(virtualKeyCode);
}

stdio_fw::KeyState KeyBuffer::getKeyState(KeyCode virtualKeyCode)
{
	return getInstance()._currentBuffer.at(virtualKeyCode);
}
