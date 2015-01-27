#include "stdafx.h"
#include "Gun.h"
#include "ResourcesManager.h"


Gun::Gun(int countBullet)
{
	for (int i = 0; i < countBullet; i++)
	{
		Bullet* temp = new Bullet(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_ITEM), ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_ITEM));
		m_gun.push_back(temp);
	}
}


void Gun::shoot(int x, int y, ShootDirection shootDir)
{
	for (std::vector<Bullet*>::iterator temp = m_gun.begin(); temp != m_gun.end(); temp++)
	{
		(*temp)->setShootDirection(shootDir);
		(*temp)->setActive(true);
		(*temp)->setPosition(x, y);

		m_giveBullet.push_back(*temp);

		temp = m_gun.erase(temp);
		break;
	}
}

Gun::~Gun()
{
	for (std::vector<Bullet*>::iterator temp = m_gun.begin(); temp != m_gun.end(); temp++)
	{
		Bullet* x = *temp;
		SAFE_DEL(x);

		temp = m_gun.erase(temp);
		if (m_gun.size() == 0)
			break;
		if (temp != m_gun.begin()) temp--;
	}

	for (std::vector<Bullet*>::iterator temp = m_giveBullet.begin(); temp != m_giveBullet.end(); temp++)
	{
		Bullet* x = *temp;
		SAFE_DEL(x);

		temp = m_giveBullet.erase(temp);
		if (m_giveBullet.size() == 0)
			break;
		if (temp != m_giveBullet.begin()) temp--;
	}
}


void Gun::update()
{
	if (m_giveBullet.size() == 0) return;

	for (std::vector<Bullet*>::iterator temp = m_giveBullet.begin(); temp != m_giveBullet.end(); temp++)
	{
		if ((*temp)->getActive())
			(*temp)->update();
		else
		{
			(*temp)->setTimeToLive(20);

			m_gun.push_back(*temp);

			temp = m_giveBullet.erase(temp);
			if (m_giveBullet.size() == 0) 
				break;
			if (temp != m_giveBullet.begin()) temp--;
		}
	}
}

void Gun::draw(Graphics* g)
{
	if (m_giveBullet.size() == 0) return;

	for (std::vector<Bullet*>::iterator temp = m_giveBullet.begin(); temp != m_giveBullet.end(); temp++)
	{
		(*temp)->draw(g);
	}
}


void Gun::setCamera(int vpx, int vpy)
{
	if (m_giveBullet.size() == 0) return;

	for (std::vector<Bullet*>::iterator temp = m_giveBullet.begin(); temp != m_giveBullet.end(); temp++)
	{
		(*temp)->setCamera(vpx, vpy);
	}
}