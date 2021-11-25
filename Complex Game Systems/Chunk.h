#pragma once
#include "Graphics.h"
#include "Sprite.h"
#include "SpriteMesh.h"
#include <map>


// This is where you create a bunch of sprites (square block) and have them stored in a class.

class Chunk
{

private:
	
	unsigned int chunkWidth;
	unsigned int chunkHeight;



public:

	Chunk(int height, int width, int xPos, int yPos);
	~Chunk();

	
};