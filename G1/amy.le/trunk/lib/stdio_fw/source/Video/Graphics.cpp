#include "GL\glew.h"

#include "stdio_fw.h"
#include "Video\Graphics.h"

namespace stdio_fw
{
	GLuint createProgram(const char* vertex_src, const char* fragment_src);
	GLuint loadShader(GLenum type, const char* src);

	Graphics::Graphics()
	{

	}

	Graphics::~Graphics()
	{

	}

	ErrorCode Graphics::initGraphics(int screenW, int screenH)
	{
		m_iScreenW = screenW;
		m_iScreenH = screenH;

		const char* solid_obj_vertex_shader_src =
			"#version 120\n"
			"attribute vec2 a_pos;\n"
			"void main()\n"
			"{\n"
			"gl_Position = vec4(a_pos, 1.0, 1.0);\n"
			"}\n";

		const char* solid_obj_fragment_shader_src = 
			"#version 120\n"
			"precision mediump float;\n"
			"uniform vec4 u_color;\n"
			"void main()\n"
			"{\n"
			"gl_FragColor = u_color;\n"
			"}\n";

		m_aPrograms[0] = createProgram(solid_obj_vertex_shader_src, solid_obj_fragment_shader_src);

		m_cachedLocs[CACHED_LOC::ATRIB_POSITION] = glGetAttribLocation(m_aPrograms[0], "a_pos");
		m_cachedLocs[CACHED_LOC::UNIFO_COLOR] = glGetUniformLocation(m_aPrograms[0], "u_color");

		return ErrorCode::ERR_NO_ERROR;
	}

	void Graphics::fillRect(int x, int y, int width, int height)
	{
		draw(x, y, width, height);
	}
	void Graphics::drawRect(int x, int y, int width, int height, int weight)
	{
		//Top
		fillRect(x, y, width, weight);
		//Bottom
		fillRect(x, y + height - weight, width, weight);
		//Left
		fillRect(x, y + weight, weight, height - (weight << 1));
		//Right
		fillRect(x + width - weight, y + weight, weight, height - (weight << 1));
	}

	void Graphics::drawLine(float x1, float y1, float x2, float y2)
	{
		
	}

	void Graphics::draw(int x, int y, int width, int height, unsigned int texture_id)
	{
		// Compute vertices array
		float vertices[] = {
			XSCREEN2GL(x, m_iScreenW), YSCREEN2GL(y, m_iScreenH),
			XSCREEN2GL(x, m_iScreenW), YSCREEN2GL(y + height, m_iScreenH),
			XSCREEN2GL(x + width, m_iScreenW), YSCREEN2GL(y + height, m_iScreenH),
			XSCREEN2GL(x, m_iScreenW), YSCREEN2GL(y, m_iScreenH),
			XSCREEN2GL(x + width, m_iScreenW), YSCREEN2GL(y + height, m_iScreenH),
			XSCREEN2GL(x + width, m_iScreenW), YSCREEN2GL(y, m_iScreenH)
		};

		GLint activeProgram = 0;
		if (texture_id == 0)	// We draw solid object
			activeProgram = m_aPrograms[0];
		else
			activeProgram = m_aPrograms[1];
		glUseProgram(activeProgram);

		// Transfer data to verties
		GLint posLoc = m_cachedLocs[CACHED_LOC::ATRIB_POSITION];
		if (posLoc != -1)
		{
			glVertexAttribPointer(posLoc, 2, GL_FLOAT, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(posLoc);
		}


		GLint colorUniLoc = m_cachedLocs[CACHED_LOC::UNIFO_COLOR];
		if (colorUniLoc != -1)
		{
			glUniform4fv(colorUniLoc, 1, &m_drawColor[0]);
		}

		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void Graphics::setColor(unsigned int color)
	{
		// [0000 0000] [0000 0000] [0000 0000] [0000 0000]
		m_drawColor[0] = ((color >> 24) & 0xFF000000) / 255.0f;
		m_drawColor[1] = ((color >> 16) & 0x00FF0000) / 255.0f;
		m_drawColor[2] = ((color >> 8) & 0x0000FF00) / 255.0f;
		m_drawColor[3] = (color & 0x000000FF) / 255.0f;
		
	}
	void Graphics::setClearColor(unsigned int color)
	{
		// [0000 0000] [0000 0000] [0000 0000] [0000 0000]
		m_clearColor[0] = ((color >> 24) & 0xFF000000) / 255.0f;
		m_clearColor[1] = ((color >> 16) & 0x00FF0000) / 255.0f;
		m_clearColor[2] = ((color >> 8) & 0x0000FF00) / 255.0f;
		m_clearColor[3] = 1.0f;
	}
	void Graphics::cleanScreen()
	{
		glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	GLuint loadShader(GLenum type, const char* src)
	{
		GLuint shader = glCreateShader(type);
		if (shader)
		{
			glShaderSource(shader, 1, &src, NULL);
			glCompileShader(shader);
			GLint compiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			if (!compiled)
			{
				GLint infoLen = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
				if (infoLen)
				{
					char* buf = (char*)malloc(infoLen);
					if (buf)
					{
						glGetShaderInfoLog(shader, infoLen, NULL, buf);
						char msg[512];
						sprintf_s(msg, 512, "Could not compile shader %d:\n%s\n", type, buf);
						ASSERT_MSG(false, msg);
						free(buf);
					}
					glDeleteShader(shader);
					shader = 0;
				}
			}
		}
		return shader;
	}

	GLuint createProgram(const char* vertex_src, const char* fragment_src)
	{
		GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertex_src);
		if (!vertexShader)
		{
			return 0;
		}

		GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, fragment_src);
		if (!pixelShader)
		{
			return 0;
		}

		GLuint program = glCreateProgram();
		if (program)
		{
			glAttachShader(program, vertexShader);
			glAttachShader(program, pixelShader);

			glLinkProgram(program);
			GLint linkStatus = GL_FALSE;
			glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
			if (linkStatus != GL_TRUE)
			{
				GLint bufLength = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
				if (bufLength)
				{
					char* buf = (char*)malloc(bufLength);
					if (buf)
					{
						glGetProgramInfoLog(program, bufLength, NULL, buf);
						char msg[512];
						sprintf_s(msg, 512, "Could not link program:\n%s\n", buf);
						ASSERT_MSG(false, msg);
						free(buf);
					}
				}
				glDeleteProgram(program);
				program = 0;
			}
		}
		if (!program)
		{
			ASSERT_MSG(false, "Could not create program.");			
		}
		return program;
	}
}
