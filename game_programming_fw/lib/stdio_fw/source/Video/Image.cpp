#include "GL\glew.h"

#include "stdio_fw.h"
#include "Video\Image.h"

#include "FreeImage.h"

namespace stdio_fw
{
	Image::Image(const char* path) :m_imgWidth(0), m_imgHeight(0), m_texID(0), m_isLoaded(false)
	{
		strcpy_s(m_imgPath, path);
	}

	Image::~Image()
	{
		unloadImage();
	}

	ErrorCode Image::loadImage()
	{
		if (m_isLoaded)
			return ErrorCode::ERR_NO_ERROR;

		// Load image data
		unsigned char* data = loadImageData();

		if (data == NULL)
			return ErrorCode::ERR_CANT_OPEN_FILE;

		// Create and bind texture
		glGenTextures(1, &m_texID);
		glBindTexture(GL_TEXTURE_2D, m_texID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_imgWidth, m_imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBindTexture(GL_TEXTURE_2D, 0);
		m_isLoaded = true;

		// Clean up
		SAFE_DEL_ARR(data);
	}

	unsigned char* Image::loadImageData()
	{
		//Automatocally detects the format(from over 20 formats!)
		FREE_IMAGE_FORMAT img_format = FreeImage_GetFileType(m_imgPath, 0);
		FIBITMAP* img_bm = FreeImage_Load(img_format, m_imgPath);

		if (img_bm == NULL)
			return NULL;

		img_bm = FreeImage_ConvertTo32Bits(img_bm);

		int img_w = FreeImage_GetWidth(img_bm);
		int img_h = FreeImage_GetHeight(img_bm);

		unsigned char* img_data = new unsigned char[4 * img_w * img_h];
		char* pixeles = reinterpret_cast<char*>(FreeImage_GetBits(img_bm));

		//FreeImage loads in BGR format, so you need to swap some bytes => RGBA.
		for (int j = 0; j < img_w * img_h; j++){
			img_data[j * 4 + 0] = pixeles[j * 4 + 2];
			img_data[j * 4 + 1] = pixeles[j * 4 + 1];
			img_data[j * 4 + 2] = pixeles[j * 4 + 0];
			img_data[j * 4 + 3] = pixeles[j * 4 + 3];
		}

		m_imgWidth = img_w;
		m_imgHeight = img_h;

		return img_data;
	}

	void Image::unloadImage()
	{
		glDeleteTextures(1, &m_texID);
		m_isLoaded = false;
	}

	void Image::scale(float ratio)
	{
		if (ratio <= 0.0f)
			return;

		m_imgWidth = static_cast<unsigned int>(m_imgWidth * ratio);
		m_imgHeight = static_cast<unsigned int>(m_imgHeight * ratio);
	}
}