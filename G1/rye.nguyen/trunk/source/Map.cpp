#include "config.h"

#include "Map.h"

#include <stdio.h>

Map::Map()
{
	m_image_path = new char*[7];
}

Map::~Map()
{

}

void Map::Release()
{
	for(int i = 0; i < 7; i++)
	{
		delete [] m_image_path[i];
		m_image_path[i] = NULL;
	}

	delete [] m_bricks_position;
	m_bricks_position = NULL;
}

void Map::ReadMap(char* path)
{
	//Open File to read data
	//Read the whole map to buffer
	//Close File when the process is completed
	//Variable:
	//size: sizeof file/sizeof buffer map
	//map: save map into buffer
	FILE *f = fopen(path, "rb");
	fseek(f, 0, SEEK_END);
	int size = ftell(f);

	fseek(f, 0, SEEK_SET);

	char* map = new char[size];
	fread(map, sizeof(char), size, f);

	fclose(f);



	//Variable:
	//current_pos: the beginning position of each image's path
	//data_size: path's size
	//buff: a copy of map. It's referrence to map
	//Using pointer arithmetics to change it's value
	int current_pos = 0;

	SetImagesPath(map, current_pos);
	SetBallVeloc(map, current_pos);
	SetBarVeloc(map, current_pos);
	SetBrickQuantity(map, current_pos);
	SetBricksPosition(map, current_pos);

	delete [] map;
	map = NULL;
}

char** Map::GetImagesPath()
{
	return m_image_path;
}

Vector2D Map::GetBallVeloc()
{
	return m_ball_veloc;
}

int Map::GetBarVeloc()
{
	return m_bar_veloc;
}

int Map::GetBrickQuantity()
{
	return m_brick_quantity;
}

int Map::GetSuperBrickQuantity()
{
	return m_super_brick_quantity;
}

Vector2D* Map::GetBricksPosition()
{
	return m_bricks_position;
}

void Map::SetImagesPath(char* map, int &current_position)
{
	int data_size;
	char* buff = map + current_position;

	for(int i = 0; i < 7; i++)
	{
		data_size = 0;

#if FLATFORM == MACOS
		//New line character in MacOS is '\r'
		while(*buff != (char)13)
#else
		//New line character in Linux is '\n'
		//New line character in Windows is "\r\n"
		//So I just gather 2 Flatforms into 1 case
		while(*buff != (char)10)
#endif
		{
			buff++;
			data_size++;
		}

#if FLATFORM == WINDOWS
		//Because in Windows, there're 2 new line characters
		data_size--;
#endif
		m_image_path[i] = new char[data_size];
		for(int j = 0; j < data_size; j++)
			m_image_path[i][j] = *(map + current_position + j);

		m_image_path[i][data_size] = NULL;
		buff++;


		//Move to next non-new line character
#if FLATFORM == WINDOWS
		current_position += data_size + 2;
#else
		current_position += data_size + 1;
#endif
	}
}

void Map::SetBallVeloc(char* map, int &current_position)
{
	//Get ball's velocity
	int data_size = 0;
	char* buff = map + current_position;

	while(*buff != (char)32)
	{
		buff++;
		data_size++;
	}
	char* ball_veloc_x = new char[data_size];
	for(int i = 0; i < data_size; i++)
		ball_veloc_x[i] = *(map + current_position + i);
	m_ball_veloc.x = ConvertToNumber(ball_veloc_x);
	buff++;
	current_position += data_size + 1;

	delete [] ball_veloc_x;
	ball_veloc_x = NULL;

	data_size = 0;
#if FLATFORM == MACOS
	while(*buff != (char)13)
#else
	while(*buff != (char)10)
#endif
	{
		buff++;
		data_size++;
	}
#if FLATFORM == WINDOWS
	data_size--;
#endif

	char* ball_veloc_y = new char[data_size];
	for(int i = 0; i < data_size; i++)
		ball_veloc_y[i] = *(map + current_position + i);
	m_ball_veloc.y = ConvertToNumber(ball_veloc_y);

	delete [] ball_veloc_y;
	ball_veloc_y = NULL;

#if FLATFORM == WINDOWS
	current_position += data_size + 2;
#else
	current_position += data_size + 1;
#endif
}

void Map::SetBarVeloc(char* map, int &current_position)
{
	int data_size = 0;
	char* buff = map + current_position;

#if FLATFORM == MACOS
	while(*buff != (char)13)
#else
	while(*buff != (char)10)
#endif
	{
		buff++;
		data_size++;
	}
#if FLATFORM == WINDOWS
	data_size--;
#endif

	char* bar_veloc = new char[data_size];
	for(int i = 0; i < data_size; i++)
		bar_veloc[i] = *(map + current_position + i);
	m_bar_veloc = ConvertToNumber(bar_veloc);
	
	delete [] bar_veloc;
	bar_veloc = NULL;
	
#if FLATFORM == WINDOWS
	current_position += data_size + 2;
#else
	current_position += data_size + 1;
#endif
}

void Map::SetBrickQuantity(char* map, int &current_position)
{
	int data_size = 0;
	char* buff = map + current_position;

	while(*buff != (char)32)
	{
		buff++;
		data_size++;
	}

	char* brick_quantity = new char[data_size];
	for(int i = 0; i < data_size; i++)
		brick_quantity[i] = *(map + current_position + i);
	m_brick_quantity = ConvertToNumber(brick_quantity);
	buff++;
	current_position += data_size + 1;

	delete [] brick_quantity;
	brick_quantity = NULL;

	data_size = 0;
#if FLATFORM == MACOS
	while(*buff != (char)13)
#else
	while(*buff != (char)10)
#endif
	{
		buff++;
		data_size++;
	}
#if FLATFORM == WINDOWS
	data_size--;
#endif

	char* super_brick_quantity = new char[data_size];
	for(int i = 0; i < data_size; i++)
		super_brick_quantity[i] = *(map + current_position + i);
	m_super_brick_quantity = ConvertToNumber(super_brick_quantity);

	delete [] super_brick_quantity;
	super_brick_quantity = NULL;

#if FLATFORM == WINDOWS
	current_position += data_size + 2;
#else
	current_position += data_size + 1;
#endif
}

void Map::SetBricksPosition(char* map, int &current_position)
{
	int data_size;
	char* buff = map + current_position;

	m_bricks_position = new Vector2D[m_brick_quantity];
	for(int i = 0; i < m_brick_quantity; i++)
	{
		data_size = 0;
		while(*buff != (char)32)
		{
			buff++;
			data_size++;
		}

		char* brick_pos_x = new char[data_size];
		for(int j = 0; j < data_size; j++)
			brick_pos_x[j] = *(map + current_position + j);
		m_bricks_position[i].x = ConvertToNumber(brick_pos_x);
		current_position += data_size + 1;
		buff++;

		delete [] brick_pos_x;
		brick_pos_x = NULL;


		data_size = 0;
#if FLATFORM == MACOS
		while(*buff != (char)13)
#else
		while(*buff != (char)10)
#endif
		{
			buff++;
			data_size++;
		}
#if FLATFORM == WINDOWS
		data_size--;
#endif

		char* brick_pos_y = new char[data_size];
		for(int j = 0; j < data_size; j++)
			brick_pos_y[j] = *(map + current_position + j);
		m_bricks_position[i].y = ConvertToNumber(brick_pos_y);

		delete [] brick_pos_y;
		brick_pos_y = NULL;
		
#if FLATFORM == WINDOWS
		current_position += data_size + 2;
		buff++;
#else
		current_position += data_size + 1;
#endif
	}
}

int Map::ConvertToNumber(char* str)
{
	int sign = 1;
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	else if(*str == '+')
		str++;

	int value = 0;
	while(*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (*str - 48);
		str++;
	}

	return value * sign;
}