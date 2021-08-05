#pragma once
#include "Graphics.h"
#include "Math.h"
#include <vector>
#include "ShaderProgram.h"


class Mesh
{
private:
	int vertCount = 0;

	GLuint vboID = -1;
	GLuint iboID = -1;
	GLuint worldLocationID = -1;

	glm::mat4 worldTransform; // Redundant(?)

	glm::vec3 offSet; // By how much to move all the points uniformly

	ShaderProgram* shaderProgramReference; //Redundant

	//std::vector<glm::vec3> vertices; // Currently a collection of positions

	struct Vertex 
	{
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 textureCoords;
	};

	std::vector<Vertex> vertices;
public:

	Mesh();
	~Mesh();
	
	void Draw();

	void FBDraw();


	void SetOffset(glm::vec3 offset);

	void CreatePoint(glm::vec3 position); 
	void CreatePoint(glm::vec3 position, glm::vec3 color);
	//void CreateTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3);

	void CreateQuad();

	void BufferMesh(); // Only binds buffers and stuff

	void FBBufferMesh();


	GLuint GetVertexBufferObjectID() {return vboID;}
	GLuint GetIndexBufferObjectID() {return iboID; }

	glm::mat4 GetWorldTransform() { return worldTransform; }
};

