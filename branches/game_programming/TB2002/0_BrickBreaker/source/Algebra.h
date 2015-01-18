#ifndef __ALGEBRA_H__
#define __ALGEBRA_H__
#include <time.h>
//----------------------------------------------------------//
/// struct vector 2D
//----------------------------------------------------------//

struct s_vector2D
{
	int X,
		Y;
	s_vector2D();
	s_vector2D(int	 newX, int   newY);
	s_vector2D(float newX, float newY);
};


//---------------------------------------------------------//

int RandomInt(int begin, int end);


#endif