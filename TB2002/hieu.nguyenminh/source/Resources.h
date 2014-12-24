#pragma once

using namespace stdio_fw;


#define IMAGE_PATH_BACKGROUND			"Image\\Background.jpg"
#define IMAGE_PATH_BALL					"Image\\Ball.png"
#define IMAGE_PATH_BAR					"Image\\Bar.png"
#define IMAGE_PATH_NORMAL_BRICK			"Image\\NormalBrick.png"
#define IMAGE_PATH_IMMORTAL_BRICK		"Image\\ImmortalBrick.png"
#define IMAGE_PATH_EXPLOSIVE_BRICK		"Image\\ExplosiveBrick.png"


#pragma region IMAGE

extern Image *_image_Background;
extern Image *_image_Ball;
extern Image *_image_Bar;
extern Image *_image_NormalBrick;
extern Image *_image_ImmortalBrick;
extern Image *_image_ExplosiveBrick;

#pragma endregion;


void InitImage();
void ReleaseImage();