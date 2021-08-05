#include "SpriteMesh.h"

SpriteMesh::SpriteMesh()
{
	CreateDefaultQuad();

	glGenBuffers(1, &vboID);
	glGenBuffers(1, &iboID);
	glGenVertexArrays(1, &vaoID);


	//Buffering the data (or sending it to the GPU
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteVertex) * spriteVertices.size(), spriteVertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Binding the VAO (and hence bindning the correct buffers and AttribArrays)
	glBindVertexArray(vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex), (const void*)(sizeof(float) * 2));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex), (const void*)(sizeof(float) * 5));

	glBindVertexArray(0); // Unbind the VAO (Finish recording / binding)

	// Unbind stuff so that the buffers can be used elsewhere
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

SpriteMesh::~SpriteMesh()
{
	glDeleteBuffers(1, &vboID);
	glDeleteBuffers(1, &iboID);
	glDeleteVertexArrays(1, &vaoID);
}

void SpriteMesh::CreateDefaultQuad() 
{
	// Default vertex positions are {-0.5f, -0.5f,}, {-0.5f, 0.5f}, { 0.5f, 0.5f}, {0.5f, -0.5f}
	// Default vertex color is {1,1,1}
	// Default textureCoords are {0,0}, {1,0} {1,1}, {0,1}
	spriteVertices.push_back({ {-0.5f, -0.5f}, {1,1,1}, {0,0} });
	spriteVertices.push_back({ {-0.5f, 0.5f}, {1,1,1}, {0,1} });
	spriteVertices.push_back({ {0.5f, 0.5f}, {1,1,1}, {1,1} });
	spriteVertices.push_back({ {0.5f, -0.5f}, {1,1,1}, {1,0} });
}

void SpriteMesh::BindMesh()
{
	glBindVertexArray(vaoID);
}


FBQuad::FBQuad()
{
	renderQuad.push_back({ { -0.5f, -0.5f }, {0, 0} });
	renderQuad.push_back({ { -0.5f, 0.5f },  {0, 1} });
	renderQuad.push_back({ { 0.5f, 0.5f}, {1, 1} });
	renderQuad.push_back({ { 0.5f, -0.5f}, {1, 0} });

	glGenBuffers(1, &vboID);
	glGenBuffers(1, &iboID);
	glGenVertexArrays(1, &vaoID);


	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(FBVertex) * renderQuad.size(), renderQuad.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * quadIndices.size(), quadIndices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(vaoID); // Begin recording the VAO
	glBindBuffer(GL_ARRAY_BUFFER, vboID); // This is what was causing the problem: GL_VERTEX_ARRAY
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(FBVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(FBVertex), (const void*)(sizeof(float) * 2));

	glBindVertexArray(0); // Finish recording the VAO

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void FBQuad::BindFBQuad()
{
	glBindVertexArray(vaoID);
}

FBQuad::~FBQuad()
{
	glDeleteBuffers(1, &vboID);
	glDeleteBuffers(1, &iboID);
	glDeleteVertexArrays(1, &vaoID);
}