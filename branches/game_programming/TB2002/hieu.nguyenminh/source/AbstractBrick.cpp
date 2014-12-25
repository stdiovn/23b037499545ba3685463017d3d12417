#include "stdafx.h"
#include "AbstractBrick.h"
#include "GameDefine.h"


AbstractBrick::AbstractBrick()
{
}


AbstractBrick::~AbstractBrick()
{
}


AbstractBrick::AbstractBrick(Vec2 _Postion) 
	: MoveableObject(_Postion, Vec2(0,0))
{

}
