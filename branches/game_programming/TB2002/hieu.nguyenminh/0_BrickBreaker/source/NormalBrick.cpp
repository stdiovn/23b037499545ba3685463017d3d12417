#include "stdafx.h"
#include "NormalBrick.h"
#include "Resources.h"
#include "GameDefine.h"


NormalBrick::NormalBrick()
{
	m_ID = ID_NORMALBRICK;
	m_Image = &_image_NormalBrick;

}

NormalBrick::NormalBrick(Vec2 _Position) : AbstractBrick(_Position)
{
	m_ID = ID_NORMALBRICK;
	m_Image = &_image_NormalBrick;

}


NormalBrick::~NormalBrick()
{
}

void NormalBrick::update(float deltaTime)
{

}