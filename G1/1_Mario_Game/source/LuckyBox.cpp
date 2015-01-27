#include "stdafx.h"
#include "LuckyBox.h"


LuckyBox::LuckyBox(ItemsType type, int countCoin)
{
	m_type = type;

	m_item = new ItemInBox(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_ITEM),
		ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_ITEM), type);

	m_box = new Box(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_TILESET),
		ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_TILESET), type, countCoin);
}

LuckyBox::LuckyBox(ItemsType type)
{
	m_type = type;

	m_item = new ItemInBox(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_ITEM),
		ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_ITEM), type);

	m_box = new Box(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_TILESET),
		ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_TILESET), type, 1);
}

LuckyBox::~LuckyBox()
{
	delete m_box;
	delete m_item;
}

void LuckyBox::update()
{
	m_box->update();
	if (m_box->finishAnimation())
		m_item->setActive(true);
	
	m_item->update();

	if (m_item->finishAnimation())
		m_box->setFinishAnimation(false);
}

void LuckyBox::draw(Graphics* g)
{
	m_item->draw(g);
	m_box->draw(g);
}

void LuckyBox::setCollision(bool x)
{
	m_box->setCollsion(x);
}

void LuckyBox::setPosition(int x, int y)
{
	m_box->setPosition(x, y);
	
	m_item->setPosition(x, y);
	m_item->getStateMachine()->GetCurrentState()->enter(m_item);
}

void LuckyBox::setCamera(int vpx, int vpy)
{
	m_box->setCamera(vpx, vpy);
	m_item->setCamera(vpx, vpy);
}

void LuckyBox::changeItemsType(ItemsType type)
{
	m_type = type;
	m_item->setItemsType(type);
}

