#include "stdafx.h"

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "config.h"

#include "Game.h"
#include <time.h>

#include "Map.h"

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::Init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::Init(screenW, screenH, title);

	//Init some default values for game
	m_is_game_over = false;
	m_is_win = false;
	m_lives = 3;
	m_is_active = true;
	m_level = 1;

	//Init map from it's path
	//Each level has one different map's path
	char* path = GetPath();
	CreateMap(path);

	SAFE_DEL_ARR(path);

	return errCode;
}

void Game::Update(float deltaTime)
{
	if(m_is_active)
	{
		//Check collides between Ball and each Brick
		for(int i = 0; i < m_brick_quantity; i++)
		{
			if(m_brick[i]->IsActive() && m_ball->IsCollisionWithObject(m_brick[i]->GetRect(), 0))
			{
				m_brick[i]->SetLive(m_brick[i]->GetLives() - 1);

				if(m_brick[i]->GetLives() == 0)
				{
					m_brick[i]->DeActivate();
					m_brick_active_left--;
				}
			}
		}



		//Update all active Brick
		for(int i = 0; i < m_brick_quantity; i++)
		{
			if(m_brick[i]->IsActive())
				m_brick[i]->Update();
		}



		//Check game win or game over
		if(m_brick_active_left == 0)
		{
			m_is_win = true;
			m_is_active = false;
		}

		if(!m_ball->IsActive())
		{
			m_lives--;
			m_is_active = false;

			if(m_lives == 0)
				m_is_game_over = true;
		}



		//Check key for moving Bar
		if(getKeyState(KeyCode::KEY_LEFT) == KeyState::KEY_PRESSED)
			m_bar->KeyPress(KeyCode::KEY_LEFT);
		else if(getKeyState(KeyCode::KEY_RIGHT) == KeyState::KEY_PRESSED)
			m_bar->KeyPress(KeyCode::KEY_RIGHT);
		else
			m_bar->KeyPress(KeyCode::KEY_UNKNOWN);



		//Check collides with Bar and update Bar
		bool collide_with_bar = m_ball->IsCollisionWithObject(m_bar->GetRect(), m_bar->GetVelocity());
		if(!collide_with_bar)
			m_bar->Update();

		m_ball->Update();
	}
	else if(getKeyState(KeyCode::KEY_ENTER))
	{
		if(m_is_game_over)
			Reset();
		else if(m_is_win)
		{
			ReleaseCurrentLevel();

			if(m_level < MAX_LEVEL)
				m_level++;

			char* path = GetPath();
			CreateMap(path);

			SAFE_DEL_ARR(path);

			m_is_win = false;
			m_is_active = true;

			m_lives = 3;
		}
	}

	//Set game reactived after 120 frames
	//Reset ball and bar to default
	else	
	{
		static int count = 0;
		count++;
		if(count >= 120)
		{
			m_is_active = true;
			count = 0;

			m_ball->Reset();
			m_bar->Reset();
		}
	}



	//Exit game
	if(IsExit())
		Exit();



	//Framerate Limited
	if(1000.0f / FRAMERATE > deltaTime)
		Sleep(1000.0f / FRAMERATE - deltaTime);
}

void Game::Render(Graphics* g)
{
	g->cleanScreen();

	g->drawImage(m_background, 0, 0);



	//Render all objects
	if(!m_is_game_over && !m_is_win)
	{
		for(int i = 0; i < m_brick_quantity; i++)
		{
			if(m_brick[i]->IsActive())
				m_brick[i]->Render(g);
		}
		m_bar->Render(g);
		m_ball->Render(g);
	}


	if(m_is_game_over)
		g->drawImage(m_game_over, 200, 150);
	else if(m_is_win)
		g->drawImage(m_win, 200, 150);
}


//Release all objects have been alloc before
void Game::Exit()
{
	ReleaseCurrentLevel();

	exit(1);
}

void Game::ReleaseCurrentLevel()
{
	m_background->unloadImage();
	SAFE_DEL(m_background);

	m_game_over->unloadImage();
	SAFE_DEL(m_game_over);

	m_win->unloadImage();
	SAFE_DEL(m_win);

	for(int i = 0; i < m_brick_quantity; i++)
	{
		m_brick[i]->Release();
		SAFE_DEL(m_brick[i])
	}
	SAFE_DEL_ARR(m_brick);

	m_bar->Release();
	SAFE_DEL(m_bar);

	m_ball->Release();
	SAFE_DEL(m_ball);
}

/////////////////////////////////////
//Support Function
/////////////////////////////////////
bool Game::IsExit()
{
	return getKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEY_PRESSED;
}

//Reset all values to its default
void Game::Reset()
{
	for(int i = 0; i < m_brick_quantity; i++)
	{
		m_brick[i]->Activate();
		m_brick[i]->SetLive(1);
	}
	m_brick_active_left = m_brick_quantity;

	int count = m_super_brick_quantity;
	while(count != 0)
	{
		int i = rand() % m_brick_quantity;

		if(m_brick[i]->GetLives() < 2)
		{
			m_brick[i]->SetLive(2);
			count--;
		}
	}

	m_bar->Reset();
	m_ball->Reset();

	m_is_game_over = false;
	m_is_active = true;

	m_lives = 3;
}

void Game::CreateMap(char* path)
{
	Map* map = new Map();
	map->ReadMap(path);

	char** image_path = map->GetImagesPath();

	m_background = new Image(image_path[0]);
	m_background->loadImage();
	m_background->scale(0.5);

	m_game_over = new Image(image_path[1]);
	m_game_over->loadImage();
	m_game_over->scale(0.5);

	m_win = new Image(image_path[2]);
	m_win->loadImage();
	m_win->scale(0.5);



	//Init several bricks
	//Position depend on variable 'i'
	//Set all brick activate
	m_brick_quantity = map->GetBrickQuantity();
	m_brick = new Brick*[m_brick_quantity];

	Vector2D* bricks_position = map->GetBricksPosition();

	for(int i = 0; i < m_brick_quantity; i++)
	{
		m_brick[i] = new Brick();
		m_brick[i]->Init(image_path[5], image_path[6], bricks_position[i].x, bricks_position[i].y, 80, 20);

		m_brick[i]->Activate();
	}
	m_brick_active_left = m_brick_quantity;

	m_super_brick_quantity = map->GetSuperBrickQuantity();
	int count = m_super_brick_quantity;
	while(count != 0)
	{
		int i = rand() % m_brick_quantity;

		if(m_brick[i]->GetLives() < 2)
		{
			m_brick[i]->SetLive(2);
			count--;
		}
	}

	m_bar = new Bar();
	m_bar->Init(image_path[4], map->GetBarVeloc());

	m_ball = new Ball();
	m_ball->Init(image_path[3], map->GetBallVeloc());

	map->Release();
	SAFE_DEL(map);
}

char* Game::GetPath()
{
	char* path = new char[13];
	strcpy(path, "map\\mapx.rye");
	path[7] = m_level + 48;
	
	return path;
}

/////////////////////////////////////
// Entry Point
/////////////////////////////////////
int main()
{
	srand(unsigned(time(NULL)));

	Game g;
	g.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Rye's Game");

	g.Run();

	return 0;
}