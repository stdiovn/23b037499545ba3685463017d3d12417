#include "stdafx.h"
#include <time.h>
#include "Game.h"
#include "BlockBar.h"
#include "STDIO_FW\Video\Image.h"

Image* back_ground;
Image* brick[15];
Image* ball;
Image* mario;
double ball_W_coordinate = 443, ball_H_coordinate = 546;
bool isStayble = true;
double n = 0;
double m = -1;
int count = 352;

BlockBar padding("D:\\Game Image\\block bar.png");

Game::Game()
{

}

Game::~Game()
{

}

ErrorCode Game::init(int screenW, int screenH, const char* title)
{
	ErrorCode errCode = Application::init(screenW, screenH, title);	
	/*back_ground = new Image("D:\\Game Image\\black-brick-wall.jpg");

	for (int i = 0; i < 15; i++)
		brick[i] = new Image("D:\\Game Image\\brick100x40.png");*/
	mario = new Image("D:\\Game Image\\mario_sprite.png");
	mario->loadImage();

	padding.init();
	padding.setXposition(450);
	padding.setYposition(560);

	return errCode;
}

void Game::update(float deltaTime)
{
	//Quit handling
	if (getKeyState(KEY_ESCAPE) == KEY_PRESSED)
		m_isRunning = false;
	
	//Block bar handling
	if (GetKeyState(stdio_fw::KEY_RIGHT) == true)
		if (padding.getXposition() < 1000)
			padding.plusXposition(0.47);

	if (GetKeyState(stdio_fw::KEY_LEFT) == true)
		if (padding.getXposition() > 0)
			padding.plusXposition(-0.47);
	
	////Ball handling
	//srand(time(NULL));
	//if (getKeyState(KEY_SPACE) == KEY_PRESSED)
	//	isStayble = false;

	//if (isStayble == false && ball_H_coordinate < 0)
	//{
	//	n = 1 * (1 - rand() %3);
	//	m = 1;
	//	isStayble = true;
	//}
	//if (isStayble == false && ball_W_coordinate > 886)
	//{
	//	n = -1;
	//	m = 1 * (1 - rand() %3);
	//	isStayble = true;
	//}
	//if (isStayble == false && ball_W_coordinate > block_bar->getWidth() && ball_W_coordinate > (block_bar->getWidth() + 250) && ball_H_coordinate == (block_bar->getHeight() - 64))
	//{
	//	n = 1 * (1 - rand() % 3);
	//	m = -1;
	//	isStayble = true;
	//}
	//if (isStayble == false && ball_H_coordinate > 586)
	//	m_isRunning = false;

	//if (isStayble == false && ball_W_coordinate < 0)
	//{
	//	n = 1;
	//	m = 1 * (1 - rand() %3);
	//	isStayble = true;
	//}
	//ball_W_coordinate += n;
	//ball_H_coordinate += m;
	//isStayble = false;
}

void Game::render(Graphics* g)
{
	g->cleanScreen();
	Sleep(100);
	g->drawRegion(mario, Rect(50, 50, 128, 256), Rect(count, 96, 32, 64));
	g->drawRegion(mario, Rect(300, 50, 128, 256), Rect(count, 0, 32, 64), FLIP_Y);
	g->drawRegion(mario, Rect(600, 50, 128, 256), Rect(count, 96, 32, 64), FLIP_X);
	count += 32;
	if (count > 608)
		count = 352;
	//g->drawImage(padding.ImagePart(), padding.getXposition(), padding.getYposition());

}

void Game::exit()
{

}

void Game::onKeyProc(KeyCode key, KeyState state)
{
	printf("Key: %c - State: %d\n", key, state);
}