#pragma once

using namespace stdio_fw;
class Game : public Application
{
private:
	Image*				m_mario;
	Rect				m_mario_rect;
	int					m_offset;

	Image*				m_enemy;
	Rect*				m_enemy_rect;
	Rect*				m_enemy_src_rect;

	int*				m_count_move;

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