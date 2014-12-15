#ifndef Default_h__
#define Default_h__

#include <string.h>
#include <sstream>

#include "stdafx.h"
#include "BrickBreaker/Core/BBMacros.h"

using namespace stdio_fw;
using namespace std;

class Default
{
public:
	static KeyCode _controlKeysArray[];

	template <class T>
	static string tostr(const T& content)
	{
		stringstream os;
		os << content;
		return string(os.str());
	}

private:
	Default();
	~Default();
};


#endif // Default_h__
