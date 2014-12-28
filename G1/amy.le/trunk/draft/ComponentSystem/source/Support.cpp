#include "stdafx.h"
#include "Support.h"
#include <string.h>
using namespace stdio_fw;


std::vector <Image*> ImageList()
{
	std::vector <Image*> m_ImageList;
	std::string image[12] = { "kolobok_01_walk_0000.png",
							  "kolobok_01_walk_0002.png",
							  "kolobok_01_walk_0004.png",
							  "kolobok_01_walk_0006.png",
							  "kolobok_01_walk_0008.png",
							  "kolobok_01_walk_0010.png",
							  "kolobok_01_walk_0012.png",
							  "kolobok_01_walk_0014.png",
							  "kolobok_01_walk_0016.png",
							  "kolobok_01_walk_0018.png",
							  "kolobok_01_walk_0020.png",
							  "kolobok_01_walk_0022.png"};
	for (int i = 0; i < 12; i ++)
	{
			Image* Img = new Image(image[i].c_str());
			Img->loadImage();
			m_ImageList.push_back(Img);
	}
	return m_ImageList;
}