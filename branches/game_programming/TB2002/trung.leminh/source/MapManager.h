//---------------------------------------------------//
// When i created this class. I want to expand it and i think it's good for other people work.
// Because it' easily to improve and expand

#ifndef __C_MAPMANAGER_H__
#define __C_MAPMANAGER_H__

#include <fstream>
#include <vector>
#include "Cloud.h"
#include "Sun.h"

using namespace std;

struct SMap	{
	vector<CCloud*> m_cloud;
	//...increase
};

class CMapManager
{
public:
	CMapManager();
	~CMapManager();

	void Init();
	void Update(CSun* sun);
	void Render(Graphics* g);
	void Release();
	SMap getMap();

private:
	SMap* m_map;
};

#endif	