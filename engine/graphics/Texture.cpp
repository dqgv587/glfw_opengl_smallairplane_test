#include "Texture.h"

Texture::Texture()
{
	id = -1;
}

Texture::Texture(int _id)
{
	id = _id;

	if (!GetTextureParams())
	{
		cout << "texture id:" << id << endl;
	}
}

Texture::Texture(string path)
{
	id = SOIL_load_OGL_texture(path.data(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA|SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams())
	{
		cout << "texture path:----------" << SOIL_last_result() << endl;
	}
}

int Texture::GetID()
{
	return id;
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

bool Texture::GetTextureParams()
{
	if (id > 0)
	{
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}
	cout << "id------------" << id << endl;
	return false;
}
