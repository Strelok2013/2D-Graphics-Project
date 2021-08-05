#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(std::string textureName)
{
	imageData = stbi_load(textureName.c_str(), &width, &height, &channels, 0);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Could add some texture filtering but not now.

	if (imageData)
	{
		if (channels == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
		
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else if (channels == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Invalid texture channels, supported channels: 3,4" << std::endl;
		}
	}
	else
	{
		std::cout << "Texture failed to load" << std::endl;
	}
	stbi_image_free(imageData);

}

Texture::~Texture()
{
	if (textureID != -1) // The check is needed to ensure there is actually something to delete inside the given textureID
	{
		glDeleteTextures(1, &textureID);
	}
}

Texture::Texture(Texture&& otherTex)
{
	if (&otherTex == this)
	{
		return;
	}

	if (textureID != -1)
	{
		glDeleteTextures(1, &textureID);
	}

	this->textureID = otherTex.textureID;
	this->height = otherTex.height;
	this->width = otherTex.width;
	this->channels = otherTex.channels;
	

	otherTex.textureID = -1; // Declare the otherTex to be clean and unuseable

}

Texture& Texture::operator=(Texture&& otherTex)
{
	if (&otherTex == this)
	{
		return *this;
	}
	if (textureID == -1)
	{
		glDeleteTextures(1, &textureID);
	}

	this->textureID = otherTex.textureID;
	this->height = otherTex.height;
	this->width = otherTex.width;
	this->channels = otherTex.channels;

	otherTex.textureID = -1;

	return *this;
}

void Texture::BindTexture(int texNumber)
{
	glActiveTexture(GL_TEXTURE0 + texNumber);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::UnbindTexture(int texNumber)
{
	glActiveTexture(GL_TEXTURE0 + texNumber);
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Texture::Exists()
{
	if (textureID)
	{
		return true;
	}
	return false;
}