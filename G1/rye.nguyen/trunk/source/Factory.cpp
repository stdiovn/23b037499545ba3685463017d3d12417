#include "stdafx.h"

#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

#include "Factory.h"

Factory::Factory()
{

}

Factory::~Factory()
{
	if(m_instance)
		SAFE_DEL(m_instance);
}

Factory* Factory::m_instance = 0;

Factory* Factory::GetInstance()
{
	if(!m_instance)
		m_instance = new Factory();

	return m_instance;
}

Entity* Factory::CreateMushroom()
{
	Entity* mushroom = new Entity();
	mushroom->Init(EntityType::ENT_MUSHROOM);

	mushroom->SetTransform(50, 50, 0.4);

	ImageList* image_list = new ImageList();

	char* image_path[MUSHROOM_FRAME_COUNT];
	int path_length = strlen(MUSHROOM_PATH);

	for(int i = 0; i < MUSHROOM_FRAME_COUNT; i++)
	{
		image_path[i] = _strdup(MUSHROOM_PATH);
		image_path[i][path_length - 6] = (i * 2) / 10 + 48;
		image_path[i][path_length - 5] = (i * 2) % 10 + 48;

		Image* image = new Image(image_path[i]);
		image->loadImage();

		image_list->push_back(image);
		SAFE_DEL(image_path[i]);
	}

	mushroom->SetAnimation(image_list);

	return mushroom;
}