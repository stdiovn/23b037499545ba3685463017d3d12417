#ifndef __MAP_H__
#define __MAP_H__

#include "support.h"

class Map
{
private:
	char**			m_image_path;

	Vector2D		m_ball_veloc;
	int				m_bar_veloc;
	
	int				m_brick_quantity;
	int				m_super_brick_quantity;
	Vector2D*		m_bricks_position;
public:
	Map();
	~Map();

	void			Release();
	void			ReadMap(char* path);

	char**			GetImagesPath();
	Vector2D		GetBallVeloc();
	int				GetBarVeloc();
	int				GetBrickQuantity();
	int				GetSuperBrickQuantity();
	Vector2D*		GetBricksPosition();

	void			SetImagesPath		(char* map, int &current_position);
	void			SetBallVeloc		(char* map, int &current_position);
	void			SetBarVeloc			(char* map, int &current_position);
	void			SetBrickQuantity	(char* map, int &current_position);
	void			SetBricksPosition	(char* map, int &current_position);
};

#endif