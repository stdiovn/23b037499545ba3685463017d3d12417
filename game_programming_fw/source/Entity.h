#pragma once
#include "STDIO_FW\stdio_fw.h"
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\Video\Graphics.h"

using namespace stdio_fw;

enum DIR
{
	LEFT = 0,
	RIGHT,
	ABOVE,
	BELOW,
	NONE,
};


class Entity
{
	~Entity();

	// Render component
	bool m_hasRenderComponent;
	int m_x;
	int m_y;
	Image *m_Image;

	// Move
	bool m_hasMoveComponent;
	int m_speed;
	int m_veclocity_vx;
	int m_veclocity_vy;

	// Collision
	bool m_hasCollisionComponent;
public:
	Entity();
	
	// Render
	void Render(Graphics *g);
	void activeRenderComponent(char *Path, int x = 0, int y = 0);
	void deActiveRender();
	void setPosition(int, int);
	int getWidth();
	int getHeight();
	int getPositionX();
	int getPositionY();
	bool isActiveRender();

	// Move
	void activeMoveComponent(int speed);
	void UpdateSpeedWithKeyBoard(KeyCode);
	void setVeclocity(int, int);
	void UpdateMovement();

	// Collision
	void activeIsCollision();
	DIR isCollisionWindows(int, int);
	bool isCollisionObject(int, int, int, int);
	DIR getOrientation(int, int, int, int);
	void UpdateCollision(int, int, int, int);

	//clear all
	void ClearAll();
};



