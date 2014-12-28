#include "stdafx.h"
#include "Entity.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
Entity::Entity()
{

}
Entity::~Entity()
{

}
void Entity::Init()
{
	m_hasMovement = false;
	m_hasRenderer = false;
	m_hasAnimation = false;
}

IDEntity Entity::GetID()
{
	return m_ID;
}

void Entity::SetID(int ID)
{
	m_ID = (IDEntity)ID;
}

void Entity::AddRender(char* Img, int X, int Y)
{
	m_hasRenderer = true;
	m_RC.m_Position.x = X;
	m_RC.m_Position.y = Y;
	m_RC.m_Image = new Image(Img);
	m_RC.m_Image->loadImage();
}


void Entity::AddMove(int K, int Angle, int Type, int CenterX, int CenterY)
{
	m_hasMovement = true;
	m_MC.m_Centre.x = CenterX;
	m_MC.m_Centre.y = CenterY;
	m_MC.m_Velocity = K;
	m_MC.m_Angle = Angle;
	m_MC.m_Type = (MoveType)Type;
}

void Entity::AddAnimation(std::vector <Image*> ImageList)
{
	m_hasAnimation = true;
	m_AC.m_ImageList = ImageList;
}

void Entity::Release()
{
}

RenderComp& Entity::GetRenderComp()
{
	return m_RC;
}
MoveComp& Entity::GetMoveComp()
{
	return m_MC;
}
AnimationComp& Entity::GetAnimationComp()
{
	return m_AC;
}

void Entity::SetImage(Image* I)
{
	m_RC.m_Image = I;
}

std::vector <Image*>& Entity::GetImageList()
{
	return m_AC.m_ImageList;
}

bool Entity::hasAnimationComponent()
{
	return m_hasAnimation;
}

bool Entity::hasMovementComponent()
{
	return m_hasMovement;
}

bool Entity::hasRendererComponent()
{
	return m_hasRenderer;
}