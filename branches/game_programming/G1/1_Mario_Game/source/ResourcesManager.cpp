#include "stdafx.h"

#include "ResourcesManager.h"

ResourcesManager::ResourcesManager()
{

}

ResourcesManager::~ResourcesManager()
{

}

ResourcesManager* ResourcesManager::m_instance = 0;

ResourcesManager* ResourcesManager::getInstance()
{
	if(!m_instance)
	{
		m_instance = new ResourcesManager();
		m_instance->loadResources();
	}

	return m_instance;
}

void ResourcesManager::loadResources()
{
	m_mario = new Image("image//mario.png");
	m_mario->loadImage();
	loadFrameList(m_marioFrameList, "image//mario.src");

	m_enemies = new Image("image//enemies.png");
	m_enemies->loadImage();
	loadFrameList(m_enemiesFrameList, "image//enemies.src");

	m_items = new Image("image//items.png");
	m_items->loadImage();
	loadFrameList(m_itemsFrameList, "image//items.src");

	m_tileSet = new Image("image//tileset_hq.png");
	m_tileSet->loadImage();
}

void ResourcesManager::unloadResources()
{
	if(m_mario)
	{
		m_mario->unloadImage();
		SAFE_DEL(m_mario)
	}
	if(m_marioFrameList)
		SAFE_DEL_ARR(m_marioFrameList);

	if(m_enemies)
	{
		m_enemies->unloadImage();
		SAFE_DEL(m_enemies);
	}
	if(m_enemiesFrameList)
		SAFE_DEL_ARR(m_enemiesFrameList);

	if(m_items)
	{
		m_items->unloadImage();
		SAFE_DEL(m_items);
	}
	if(m_itemsFrameList)
		SAFE_DEL_ARR(m_itemsFrameList);

	if(m_tileSet)
	{
		m_tileSet->unloadImage();
		SAFE_DEL(m_tileSet);
	}
}

Image* ResourcesManager::getResource(SpriteSheet sheet)
{
	if(sheet == SpriteSheet::SHEET_MARIO)
		return m_mario;
	else if(sheet == SpriteSheet::SHEET_ENEMIES)
		return m_enemies;
	else if(sheet == SpriteSheet::SHEET_ITEM)
		return m_items;
	else if(sheet == SpriteSheet::SHEET_TILESET)
		return m_tileSet;
	else
		return NULL;
}

std::vector<Frame>* ResourcesManager::getFrameList(SpriteSheet sheet)
{
	if(sheet == SpriteSheet::SHEET_MARIO)
		return m_marioFrameList;
	else if(sheet == SpriteSheet::SHEET_ENEMIES)
		return m_enemiesFrameList;
	else if(sheet == SpriteSheet::SHEET_ITEM)
		return m_itemsFrameList;
	else
		return NULL;
}

void ResourcesManager::loadFrameList(std::vector<Frame>*& frameList, const char* path)
{
	FILE* f = fopen(path, "rb");
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buff = new char[size];
	fread(buff, sizeof(char), size, f);

	fclose(f);

	if(!frameList)
		frameList = new std::vector<Frame>();

	int offset = 0;
	while(offset < size)
	{
		Frame temp;
		while(*(buff + offset++) != '=');
		offset++;
		while(*(buff + offset) != '\"')
		{
			temp.m_id += *(buff + offset);
			offset++;
		}
		offset++;


		while(*(buff + offset++) != '=');
		offset++;
		while(*(buff + offset) != ',')
		{
			temp.m_frameRect.x *= 10;
			temp.m_frameRect.x += *(buff + offset++) - '0';
		}
		offset++;
		while(*(buff + offset) != ',')
		{
			temp.m_frameRect.y *= 10;
			temp.m_frameRect.y += *(buff + offset++) - '0';
		}
		offset++;
		while(*(buff + offset) != ',')
		{
			temp.m_frameRect.width *= 10;
			temp.m_frameRect.width += *(buff + offset++) - '0';
		}
		offset++;
		while(*(buff + offset) != ')')
		{
			temp.m_frameRect.height *= 10;
			temp.m_frameRect.height += *(buff + offset++) - '0';
		}
		offset += 3;

		frameList->push_back(temp);
	}
}