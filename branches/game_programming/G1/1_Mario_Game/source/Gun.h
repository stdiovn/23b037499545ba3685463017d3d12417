#pragma once
#include "Bullet.h"

class Gun
{
	std::vector<Bullet*>		m_gun;

	// give bullet is moving
	std::vector<Bullet*>		m_giveBullet;
public:
	Gun(int countBullet);
	
	void						shoot(int x, int y, ShootDirection shootDir);
	
	std::vector<Bullet*>		getBulletShooted(){ return m_giveBullet; }

	void						update();

	void						setCamera(int vpx, int vpy);

	void						draw(Graphics* g);

	~Gun();
};

