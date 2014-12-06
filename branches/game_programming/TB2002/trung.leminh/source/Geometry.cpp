#include "stdafx.h"
#include "Geometry.h"
#include "STDIO_FW\stdio_fw.h"
using namespace stdio_fw;

//--------------------------------------------------------------------------------------------------------------------------------
/// @description: check intersect both rectangle
/// @parameter:   Rect rectangle1, Rect rectangle2
/// @return type: bool. If have collis. return true and else
/// @warning : 
//---------------------------------------------------------------------------------------------------------------------------------
bool checkIntersectRectangle(Rect rectangle1, Rect rectangle2)
{

	if (rectangle1.x + rectangle1.width <= rectangle2.x) // r1 left r2
		return false;
	if (rectangle2.x + rectangle2.width <= rectangle1.x) // r1 right r2
		return false;
	if (rectangle1.y - rectangle1.height >= rectangle2.y) // r1 top r2
		return false;
	if (rectangle2.y - rectangle2.height >= rectangle1.y) // r1 above r2
		return false;

	return true;
}