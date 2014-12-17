#ifndef __MAP_MANAGER_H__
#define __MAP_MANAGER_H__
#include "Wood.h"
#include "Stone.h"
#include "Brick.h"
#include "Ball.h"
#include <vector>
#include <fstream>

struct SMap{
	wstring m_nameMap;
	std::vector<CBrick*> m_brick;
	SMap(wstring nameMap)
	{
		m_nameMap = L"Map1.txt";
	};
};

class CMapmanager
{
public:
	CMapmanager();
	~CMapmanager();

	void loadMap();
	//void reloadNap();

	e_KindOfBrick getNameBrick(wstring name);
	void Init();
	void Update(float deltaTime, CBall* ball);
	void Render(Graphics* g);
	void Release();
	SMap getMap();
private:
	SMap* m_map;
};

#endif