#ifndef _Component_
#define _Component_
#include "STDIO_FW\Video\Image.h"

using namespace stdio_fw;




enum IDComponent
{
	COM_SPRITE,
	COM_FONT,
	COM_RENDER,
	COM_POSITION
};

struct Component
{
	Component()
	{};
};

struct Position : public Component
{
	int x, y;
	Position(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

struct RenderComponent : public Component
{
	Image *m_Image;

	RenderComponent(char *Path)
	{
		m_Image = new Image(Path);
		m_Image->loadImage();
	}
	~RenderComponent()
	{
		m_Image->unloadImage();
		delete m_Image;
	}
};

struct SpriteComponent : public Component
{
	Image *m_Image;
	int m_Id;
	int m_SpritePerCow;
	int m_Count;
	int m_Width, m_Height;
	int m_Src_x, m_Src_y;
	SpriteComponent(char *Pathimage, int SpritePerCow, int Count)
	{
		m_Image = new Image(Pathimage);
		m_Image->loadImage();
		m_Width = m_Image->getWidth() / SpritePerCow;
		m_Height = m_Image->getHeight() / (Count / SpritePerCow);
		m_Id = 0;
		m_SpritePerCow = SpritePerCow;
		m_Count = Count;
	}
	void Next()
	{
		m_Id++;

		if (m_Id > m_Count - 1) m_Id = 0;
	}
	~SpriteComponent()
	{
		m_Image->unloadImage();
		delete m_Image;
	}
};

//------- FontComponent
struct InformationFont
{
	char Byte;
	int X;
	int Y;
	int Width;
	int Height;
};

//void setEmpty(char *s, int size)
//{
//	for (int i = 0; i < size; i++)
//		s[i] = 0;
//}

struct FontComponent : public Component
{
	int N;
	char *m_Text;
	InformationFont m_InforFont[256];
	Image *m_Image;
	FontComponent(char *Path, char *Text)
	{
		m_Text = Text;

		FILE *file = fopen(Path, "r");

		if (file != NULL)
		{
			char s[1024];
			N = 0;

			while (!feof(file))
			{
				for (int i = 0; i < 1024; i++)
					s[i] = 0;
				fgets(s, 1024, file);

				if (strstr(s, "Image=\""))
				{
					char temp[1024] = "Data//Font//";
					int n = strlen(temp);

					for (int i = 0 + strlen("Image=\""); i < strlen(s); i++)
					{
						if (s[i] == '"')
							break;
						temp[n++] = s[i];
					}

					m_Image = new Image(temp);
					m_Image->loadImage();
				}
				else if (strstr(s, "char=\""))
				{
					m_InforFont[N].Byte = *(strstr(s, "char=\"") + strlen("char=\""));
				}

				if (strstr(s, "x="))
				{
					m_InforFont[N].X = atoi(strstr(s, "x=") + strlen("x="));
				}

				if (strstr(s, "y="))
				{
					m_InforFont[N].Y = atoi(strstr(s, "y=") + strlen("y="));
				}

				if (strstr(s, "width="))
				{
					m_InforFont[N].Width = atoi(strstr(s, "width=") + strlen("width="));
				}

				if (strstr(s, "height="))
				{
					m_InforFont[N].Height = atoi(strstr(s, "height=") + strlen("height="));

					N++;
				}
			}


			fclose(file);
		}
	}
	~FontComponent()
	{
		m_Image->unloadImage();
		delete m_Image;
	}
};
#endif