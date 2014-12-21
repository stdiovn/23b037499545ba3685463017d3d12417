#pragma once

using namespace stdio_fw;


#define BACKGROUND_IMAGE_PATH "Image\\BackGround.jpg"
#define BRICK_IMAGE_PATH "Image\\Brick.png"
#define BALL_IMAGE_PATH	"Image\\Ball.png"
#define BAR_IMAGE_PATH "Image\\Bar.png"


#pragma region IMAGE

extern Image *_image_BackGround;
extern Image *_image_Brick;
extern Image *_image_Ball;
extern Image *_image_Bar;

#pragma endregion;


void InitImage();
void ReleaseImage();