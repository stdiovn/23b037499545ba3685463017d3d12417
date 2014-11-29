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

Entity* Factory::CreatePlayer(char* player_name)
{
	Entity* player = new Entity();
	player->Init(EntityType::ENT_PLAYER);

	player->SetComponent(new Transform(50, 200), ComponentType::COM_TRANSFORM);
	player->SetComponent(CreateText(player_name), ComponentType::COM_LABEL);

	return player;
}

Label* Factory::CreateText(char* text)
{
	/////////////////////////////////////////////////
	//Read from file
	FILE* f = fopen("font//myfont.rye", "rb");

	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buff = new char[size];
	fread(buff, sizeof(char), size, f);

	fclose(f);
	/////////////////////////////////////////////////

	/////////////////////////////////////////////////
	//Get Image path
	char* temp = buff;
	int count = 0;
	while(*(temp + count++) != '\"');
	temp += count;
	count = 0;

	while(*(temp + count++) != '\"');

	char* font_path = new char[count];
	for(int i = 0; i < count; i++)
	{
		font_path[i] = *(temp + i);
	}
	font_path[count - 1] = '\0';

#if PLATFORM == WINDOWS
	temp += count + 2;
#else
	temp += count + 1;
#endif
	
	Image* font = new Image(font_path);
	font->loadImage();

	SAFE_DEL_ARR(font_path);
	/////////////////////////////////////////////////

	int count_char = 0;
	for(int i = 0; i < size; i++)
	{
		if(*(buff + i) == '\n')
			count_char++;
	}
	char* character = new char[count_char];
	character[count_char - 1] = '\0';

	int* character_offset = new int[count_char - 1];
	Rect** character_map = new Rect*[count_char - 1];

	for(int i = 0; i < count_char - 1; i++)
	{
		/////////////////////////////////////////////////
		
		//Get character
		while(*temp++ != '\'');
		character[i] = *temp;
		/////////////////////////////////////////////////

		character_map[i] = new Rect();

		char* temp2;
		/////////////////////////////////////////////////
		//Get x value
		while(*temp++ != '=');
		while(*temp != ' ')
		{
			character_map[i]->x *= 10;
			character_map[i]->x += INT(*temp);

			temp++;
		}

		/////////////////////////////////////////////////

		/////////////////////////////////////////////////
		//Get y value
		while(*temp++ != '=');
		while(*temp != ' ')
		{
			character_map[i]->y *= 10;
			character_map[i]->y += INT(*temp);

			temp++;
		}
		/////////////////////////////////////////////////

		/////////////////////////////////////////////////
		//Get width value
		while(*temp++ != '=');
		while(*temp != ' ')
		{
			character_map[i]->width *= 10;
			character_map[i]->width += INT(*temp);

			temp++;
		}
		/////////////////////////////////////////////////

		/////////////////////////////////////////////////
		//Get height value
		while(*temp++ != '=');
		while(*temp != ' ')
		{
			character_map[i]->height *= 10;
			character_map[i]->height += INT(*temp);

			temp++;
		}
		/////////////////////////////////////////////////

		/////////////////////////////////////////////////
		//Get character offset
		character_offset[i] = 0;
		while(*temp++ != '=');
		while(*temp != '\r')
		{
			character_offset[i] *= 10;
			character_offset[i] += INT(*temp);

			temp++;
		}
		/////////////////////////////////////////////////

		while(*temp++ != '\n');
	}

	SAFE_DEL_ARR(buff);

	Label* label = new Label(font, text, character, character_map, 3, character_offset);

	return label;
}