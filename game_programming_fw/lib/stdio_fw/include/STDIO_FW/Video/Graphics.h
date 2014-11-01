#pragma once

namespace stdio_fw
{
	enum CACHED_LOC
	{		
		// Solid object
		ATRIB_POSITION0 = 0,
		UNIFO_COLOR,
		// Image
		ATRIB_POSITION1,
		ATRIB_TEXCOORD,
		UNIFO_TEXTURE
	};

	class Image;
	class Graphics
	{
		// We use 2 program: 0 for SOLID OBJECT and 1 for IMAGE
		unsigned int		m_aPrograms[2];

		// Cache attribute and uniforms location here
		int					m_cachedLocs[5];


		float				m_drawColor[4];
		float				m_clearColor[4];

		int					m_iScreenW;
		int					m_iScreenH;
	public:
		Graphics();
		~Graphics();

		ErrorCode			initGraphics(int screenW, int screenH);

		void				fillRect(int x, int y, int width, int height);
		void				drawRect(int x, int y, int width, int height, int weight = 1);
		void				drawLine(float x1, float y1, float x2, float y2);

		void				drawImage(Image* img, int x, int y);
		void				drawRegion(Image* img, int x, int y, int src_x, int src_y, int src_w, int src_h);

		// Set color function: 0xRRGGBBAA
		void				setColor(unsigned int color);
		void				setClearColor(unsigned int color);

		void				cleanScreen();	

	private:
		void				draw(int x, int y, int width, int height, float *uv = nullptr, unsigned int texture_id = 0);
	};
}