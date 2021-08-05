#pragma once
#include "Graphics.h"
#include "glm.hpp"
#include "Util.h"


class Texture
{
private:
	GLuint textureID;

	int height;
	int width;
	int channels;
	unsigned char* imageData;


public:
	Texture() {};
	Texture(std::string textureName); // Create a texture from a filename (supports RGB and RGBA channels for now);
	// Get some copy/assign operators here potentially
	~Texture();

	Texture(const Texture& otherTex) = delete; // Copy constructor (why does it delete?)
	Texture(Texture&& otherTex); // Move constructor

	Texture& operator=(const Texture& otherTexture) = delete; // Assignment opertator (why does it delete?)
	Texture& operator=(Texture&& otherTex); // Move assign operator

	void BindTexture(int texNumber); // Bind the texture for drawing
	void UnbindTexture(int texNumber); // Unbind the texture to allow others to be drawn

	bool Exists();

};