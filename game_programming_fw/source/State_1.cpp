#include "stdafx.h"
#include "State_1.h"
#define FileMap "data//Map_1.txt"
State_1::State_1()
{
	BackGround::BackGround(FileMap);
	m_BackGround = ImageSource::GetInstance()->GetImage(KindOfImage::Map_1);
}