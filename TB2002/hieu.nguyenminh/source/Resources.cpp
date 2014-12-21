#include "stdafx.h"
#include "Resources.h"


#pragma region IMAGE

Image *_image_BackGround;
Image *_image_Brick;
Image *_image_Ball;
Image *_image_Bar;

#pragma endregion;


void InitImage()
{
	_image_BackGround = new Image(BACKGROUND_IMAGE_PATH);
	_image_Brick = new Image(BRICK_IMAGE_PATH);
	_image_Ball = new Image(BALL_IMAGE_PATH);
	_image_Bar = new Image(BAR_IMAGE_PATH);

	_image_BackGround->loadImage();
	_image_Brick->loadImage();
	_image_Ball->loadImage();
	_image_Bar->loadImage();
}


void ReleaseImage()
{
	delete _image_BackGround;
	delete _image_Brick;
	delete _image_Ball;
	delete _image_Bar;
}