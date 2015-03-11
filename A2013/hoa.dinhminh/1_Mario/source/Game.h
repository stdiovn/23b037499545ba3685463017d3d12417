#pragma once

using namespace stdio_fw;
class CTileMap;


class Game : public Application
{
private:
	CTileMap* m_tilemap;
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		exit();

	virtual void		onKeyProc(KeyCode key, KeyState state);
};