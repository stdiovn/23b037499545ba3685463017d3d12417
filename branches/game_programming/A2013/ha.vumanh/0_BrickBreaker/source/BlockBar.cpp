#include "stdafx.h"
#include "BlockBar.h"
using namespace stdio_fw;

BlockBar::BlockBar(const char* ImagePart)
{
	imagepart = new Image(ImagePart);
}

void BlockBar::init()
{
	imagepart->loadImage();
}

Image* BlockBar::ImagePart()
{
	return imagepart;
}

void BlockBar::setXposition(double x)
{
	X_position = x;
}

void BlockBar::setYposition(double y)
{
	Y_position = y;
}

void BlockBar::plusXposition(double plusvalue)
{
	X_position += plusvalue;
}

double BlockBar::getXposition()
{
	return X_position;
}

double BlockBar::getYposition()
{
	return Y_position;
}

BlockBar::~BlockBar()
{
	imagepart->unloadImage();
	delete imagepart;
}