#ifndef __CTILEMAP__H__
#define __CTILEMAP__H__
using namespace stdio_fw;
/*
class CTilemap
{
private:
	int m_width;
	int m_height;
	int m_tilewidth;
	int m_tileheight;
	char m_orientation[256];
	char m_tilesetsource[256];
	int m_tilesetwidth;
	int m_tilesetheight;
	int m_xtileset;
	int m_ytileset;
	char m_type[256];
	int** m_data;
	Image* m_tilesetimg;
	void drawtile(Graphics* g, int index);
public:
	CTilemap();
	ErrorCode loadMap(char* _path);

};
*/
struct STile
{
	int m_width;
	int m_height;
};


class CTileMap
{
private:
	int m_map_width;
	int m_map_height;
	STile m_tile_map;
	STile m_tile_set;
	char m_tile_set_source[256];
	Image* m_tile_set_img;
	//int m_current_top_left_col;
	//int m_current_top_left_row;
	int** m_data_map;

	bool isNumber(char* str);
	int toInt(char* str);
	int findFirstChar(char* src, char ch, int startIndex = 0);
	char* subStr(char* src, int startIndex, int endIndex);
	void parseInfo(char* info);
public:
	CTileMap();
	ErrorCode load(char* map_file_path);
	void drawTile(Graphics* g, int index_of_tile, int x_map, int y_map);
	void drawMap(Graphics*g);
};

#endif