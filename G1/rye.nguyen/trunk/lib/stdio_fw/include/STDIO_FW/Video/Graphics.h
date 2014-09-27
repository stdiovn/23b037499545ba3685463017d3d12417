#pragma once

namespace stdio_fw
{
	enum CACHED_LOC
	{
		ATRIB_POSITION = 0,
		// Solid object		
		UNIFO_COLOR,
		// Image
		ATRIB_TEXCOORD,
		UNIFO_TEXTURE
	};

	class Graphics
	{
		// We use 2 program: 0 for SOLID OBJECT and 1 for IMAGE
		unsigned int		m_aPrograms[2];

		// Cache attribute and uniforms location here
		int					m_cachedLocs[4];


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

		// Set color function: 0xRRGGBBAA
		void				setColor(unsigned int color);
		void				setClearColor(unsigned int color);

		void				cleanScreen();	

	private:
		void				draw(int x, int y, int width, int height, unsigned int texture_id = 0);
	};
}