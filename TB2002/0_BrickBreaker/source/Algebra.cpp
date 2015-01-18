#include "stdafx.h"
#include "Algebra.h"


s_vector2D::s_vector2D() : X(0), Y(0)
{
}

s_vector2D::s_vector2D(int newX, int newY) : X(newX), Y(newY)
{ 
}

s_vector2D::s_vector2D(float newX, float newY) : X(newX), Y(newY)
{

}

/// @description :	funtion random for time
/// @param		 :	int begin and int end : random from begin to end
/// @return		 :	number
///	@warning	 :	dumplication
//---------------------------------------------------------//
int RandomInt(int begin, int end)
{
	srand(time(NULL));
	return rand() % end + begin;
}