#include "stdafx.h"

#include <string>

#include "support.h"

bool isCollide(Rect st, Rect nd)
{
	return st.x + st.width >= nd.x && st.x <= nd.x + nd.width && st.y + st.height >= nd.y && st.y <= nd.y + nd.height;
}