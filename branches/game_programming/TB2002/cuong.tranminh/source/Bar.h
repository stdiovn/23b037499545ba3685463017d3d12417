#pragma once
#include "DynamicObject.h"
class Bar :
	public DynamicObject
{
public:
	void Init();
	void Update();
	void Render(Graphics* g);
	void moveleft();
	void moveright();

	Bar();
	~Bar();
};

