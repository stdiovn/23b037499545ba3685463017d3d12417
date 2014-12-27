#pragma once

using namespace stdio_fw;
class Game : public Application
{
private:
	Image*				m_mario;
	Rect				m_mario_rect;

	int					m_default_veloc;
	int					m_veloc;
	int					m_offset;
	int					m_is_jumping;

	Image*				m_map;

	Image*				m_enemy;
	Rect*				m_enemy_rect;
	Rect*				m_enemy_src_rect;
	int*				m_enemy_veloc;

	GameState			m_state;
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		exit();

	virtual void		onKeyProc(KeyCode key, KeyState state);
};