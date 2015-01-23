#include <queue>

struct Event
{
	stdio_fw::KeyCode code;
	stdio_fw::KeyState state;
};

class InputMnr
{
private:
	static InputMnr* m_IMr;
	std::queue<Event> m_evtQueue;
	InputMnr();
	~InputMnr();
public:
	static InputMnr* createIMr();
	static void freeIMr();
};