#pragma once
#include "Math.h"
#include "Graphics.h"
#include "Util.h"
#include "Texture.h"

struct SpriteVertex
{
	glm::vec2 position;
	glm::vec3 color;
	glm::vec2 textureCoords;

};

class SpriteMesh
{
	friend class Sprite;
private:

	std::vector<SpriteVertex> spriteVertices;

	GLuint vboID = -1; 
	GLuint iboID = -1; 

	GLuint vaoID;

	std::vector<unsigned int> indices = { 0,1,2,
										  0,2,3 };

	int indexCount = 6;

public:

	SpriteMesh();
	~SpriteMesh();

	void BindMesh(); // Binds the mesh for drawing
	
	void CreateDefaultQuad(); // Creates a default quad for drawing sprites.
};

struct FBVertex
{
	glm::vec2 position;
	glm::vec2 uvs;
};

class FBQuad
{
	friend class Framebuffer;
private:
	GLuint vboID = -1;
	GLuint iboID = -1;
	GLuint vaoID = -1;


	std::vector<FBVertex> renderQuad;

	std::vector<unsigned int> quadIndices = { 0,1,2,
											  0,2,3 };
public:
	FBQuad(); // Creates a mesh specifically for framebuffers (DO NOT USE WITH REGULAR SPRITES OR VICE VERSA)
	void BindFBQuad(); // Binds the mesh for drawing
	~FBQuad();
};