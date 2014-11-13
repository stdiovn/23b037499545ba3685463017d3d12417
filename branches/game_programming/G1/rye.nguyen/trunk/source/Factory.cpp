#include "stdafx.h"

#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

#include "Factory.h"

Factory::Factory()
{

}

Factory::~Factory()
{

}

Factory* Factory::m_instance = 0;

Factory* Factory::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new Factory();
		m_instance->Init();
	}

	return m_instance;
}

void Factory::Init()
{

}

void Factory::Release()
{
	if(m_instance)
		SAFE_DEL(m_instance);
}

Entity* Factory::CreateMushroom()
{
	Entity* mushroom = new Entity();
	mushroom->Init(EntityType::ENT_MUSHROOM);

	mushroom->SetComponent(new Transform(50, 50), ComponentType::COM_TRANSFORM);

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
		delete[] image_path[i];
	}

	mushroom->SetComponent(new Animation(image_list), ComponentType::COM_ANIMATION);

	return mushroom;
}
//
//Entity* Factory::CreatePlayer()
//{
//	Entity* player = new Entity();
//
//	player->SetTransform(10, 360, 2);
//
//	player->SetMovement(3, 0);
//	player->GetMovement()->m_type = MoveType::MOVE_PLAYER_CONTROL;
//
//	return player;
//}