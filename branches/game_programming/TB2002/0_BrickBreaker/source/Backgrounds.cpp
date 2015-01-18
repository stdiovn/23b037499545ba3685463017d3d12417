#include "stdafx.h"
#include "Backgrounds.h"
#include "Algebra.h"

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: constructor no parametter. Using create position of background
/// @parameter:   No. 
/// @return type: No.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
CBackgrounds::CBackgrounds()
{
	m_position.X = 0;
	m_position.Y = 0;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Constructor have a param. 
/// @parameter:   filePath. It's file path of image (background)
/// @return type: No.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
CBackgrounds::CBackgrounds(const char* filePath, int posX, int posY)
{
	m_texture = new Image(filePath);
	m_position.X = posX;
	m_position.Y = posY;
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Destructor
/// @parameter:   No 
/// @return type: No.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
CBackgrounds::~CBackgrounds()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Using load resource
/// @parameter:   No
/// @return type: ErorCode. This's enum return result when load Image
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
ErrorCode CBackgrounds::Init()
{
	return (ErrorCode) m_texture->loadImage();
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Nothing
/// @parameter:   Nothing. 
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void CBackgrounds::Update(float deltaTime)
{

}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Render image.
/// @parameter:   deltaTime. 
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void CBackgrounds::Render(Graphics* g)
{
	g->drawImage(m_texture, m_position.X, m_position.Y);
}

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: Release resource.Exactly it release m_texture
/// @parameter:   Nothing . 
/// @return type: void.
/// @warning : .
//---------------------------------------------------------------------------------------------------------------------------------
void CBackgrounds::Release()
{
	delete m_texture;
}