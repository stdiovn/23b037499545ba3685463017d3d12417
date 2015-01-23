#include "stdafx.h"
using namespace stdio_fw;

class BlockBar
{
private:
	Image* imagepart;
	double X_position;
	double Y_position;
public:
	BlockBar(const char*);
	void init();
	Image* ImagePart();
	void setXposition(double);
	void setYposition(double);
	void plusXposition(double);
	double getXposition();
	double getYposition();
	~BlockBar();
};