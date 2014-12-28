#include "stdafx.h"
#include "Resources.h"


#pragma region IMAGE

Image *_image_Background;
Image *_image_Ball;
Image *_image_Bar; 
Image *_image_NormalBrick;
Image *_image_ImmortalBrick;
Image *_image_ExplosiveBrick;

#pragma endregion;


void InitImage()
{
	_image_Background = new Image(IMAGE_PATH_BACKGROUND);
	_image_Ball = new Image(IMAGE_PATH_BALL);
	_image_Bar = new Image(IMAGE_PATH_BAR);
	_image_NormalBrick = new Image(IMAGE_PATH_NORMAL_BRICK);
	_image_ImmortalBrick = new Image(IMAGE_PATH_IMMORTAL_BRICK);
	_image_ExplosiveBrick = new Image(IMAGE_PATH_EXPLOSIVE_BRICK);

	_image_Background->loadImage();
	_image_Ball->loadImage();
	_image_Bar->loadImage();
	_image_NormalBrick->loadImage();
	_image_ImmortalBrick->loadImage();
	_image_ExplosiveBrick->loadImage();
}


void ReleaseImage()
{
	delete _image_Background;
	delete _image_Ball;
	delete _image_Bar;
	delete _image_NormalBrick;
	delete _image_ImmortalBrick;
	delete _image_ExplosiveBrick;
}