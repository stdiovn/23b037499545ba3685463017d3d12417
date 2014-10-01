#pragma once

using namespace stdio_fw;

#define SCREEN_WIDTH		800
#define SCREEN_HEIGHT		600

#define FRAMERATE			60

#define RANDOM_RED			rand() % (0xFF + 1) << 8 * 3
#define RANDOM_GREEN		rand() % (0xFF + 1) << 8 * 2
#define RANDOM_BLUE			rand() % (0xFF + 1) << 8
#define ALPHA				0xFF

typedef struct Vector2D
{
	int		x;
	int		y;
}SVector2D;

typedef struct Rect
{
	int		x;
	int		y;
	int		width;
	int		height;
}SRect;

class Game : public Application
{
private:
	Rect				m_object;
	Rect				m_bar;

	DWORD32				m_object_color;
	DWORD32				m_bar_color;

	Vector2D			m_velocity;
	int					m_bar_velocity;
public:
	Game();
	virtual				~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();

	virtual bool		IsCollidedLeft();
	virtual bool		IsCollidedRight();
	virtual bool		IsCollidedTop();
	virtual bool		IsCollidedBottom();

	virtual bool		IsKeyLeft();
	virtual bool		IsKeyRight();
	virtual bool		IsExit();
};