#pragma once

using namespace stdio_fw;
class ResourcesManager
{
private:
	static ResourcesManager*	m_instance;

	Image*		m_mario;
	Frame*		m_marioFrameList;

	Image*		m_enemies;
	Frame*		m_enemyFrameList;

	Image*		m_item;
	Frame*		m_itemFrameList;

	Image*		m_tileSet;
public:
	ResourcesManager();
	~ResourcesManager();

	static ResourcesManager* getInstance();

	ErrorCode		loadResources();
	void			unloadResources();

	void		loadImage();
	void		loadSpriteInfo();

	Image*		getResource(SpriteSheet sheet);
	Frame*		getFrame(SpriteSheet sheet);
};