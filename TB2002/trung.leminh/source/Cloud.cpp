
#include "stdafx.h"
#include "Cloud.h"


CCloud::CCloud()
{
}


CCloud::~CCloud()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Constructor have parameter. We use it for create cloud-object
/// @parameter:   int positionX, int positionY, int velocityX, int velocityY
/// @return type: Nothing.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
CCloud::CCloud(int positionX, int positionY, int velocityX, int velocityY)
{
	m_posX = positionX;
	m_posY = positionY;
	m_velX = velocityX;
	m_velY = velocityY;	// dangerous

	m_texture = new Image("BlueCloud.png");
	m_texture->loadImage();
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Initialize Sun object
/// @parameter:   No
/// @return type: ErrorCode .We will know some error if image can not load or initialize.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
ErrorCode CCloud::Init()
{
	return ErrorCode::ERR_NO_ERROR;
	// update late.
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: update status cloud-object
/// @parameter:   float deltaTime.
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CCloud::Update(float deltaTime)
{

}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Update event handle to cloud-object
/// @parameter:   No
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CCloud::UpdateEventHandle()
{
	// nothing to say.
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render cloud object to screen
/// @parameter:   Graphics8 g
/// @return type: void.
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
void CCloud::Render(Graphics* g)
{
	g->drawImage(m_texture, m_posX, m_posY, 0);
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Release resource
/// @parameter:   No
/// @return type: void.
/// @warning :	  Alway remember it
//---------------------------------------------------------------------------------------------------------------------------------
void CCloud::Release()
{
	delete m_texture;
}
