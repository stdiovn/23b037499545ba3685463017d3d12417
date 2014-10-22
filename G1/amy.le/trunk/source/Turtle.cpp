#include "Turtle.h"
#define TurtleImage "Net2.png"
#define TurtleWidth 100
#define TurtleHeight 100
Turtle::Turtle()
{
}

void Turtle::Init()
{
	m_Rect = new Rect;
	m_Rect->Init(0, 500, 10, 10, TurtleWidth, TurtleHeight);
	m_Image = new Image(TurtleImage);
	m_Image->loadImage();
}
Rect* Turtle::GetRect()
{
	return m_Rect;
}
Image* Turtle::GetImage()
{
	return m_Image;
}
void Turtle::Release()
{
	delete m_Rect;
	delete m_Image;
}

Turtle::~Turtle()
{
}
