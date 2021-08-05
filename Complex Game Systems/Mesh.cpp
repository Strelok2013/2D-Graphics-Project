#include "Mesh.h"

Mesh::Mesh()
{

	// WorldTransformID buffer needed

	worldTransform = glm::mat4(1); 
	offSet = { 0,0,0 };

}

void Mesh::CreatePoint(glm::vec3 position)
{
	vertices.push_back({ {position}, {1,1,1}, {0,0} });
	vertCount++;
}

void Mesh::CreatePoint(glm::vec3 position, glm::vec3 color)
{
	vertices.push_back({ {position}, {color}, {0,0} });
	vertCount++;
}

void  Mesh::CreateQuad()
{
	vertices.push_back({ {-0.5f, -0.5f, 0.0f}, {1, 1, 1}, {0,0} });
	vertices.push_back({ {-0.5f, 0.5f, 0.0f}, {1, 1, 1}, {0,1} });
	vertices.push_back({ {0.5f, 0.5f, 0.0f}, {1, 1, 1}, {1,1} });
	vertices.push_back({ {0.5f, -0.5f, 0.0f}, {1, 1, 1}, {1,0} });
	vertCount += 4;
}

//void Mesh::CreateTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3)
//{
//	vertices.push_back(pos1);
//	vertices.push_back(pos2);
//	vertices.push_back(pos3);
//	vertCount += 3;
//}

void Mesh::SetOffset(glm::vec3 offSet)
{
	this->offSet = offSet;
}

Mesh::~Mesh()
{

}

void Mesh::BufferMesh()
{
	// Set up handles
	glGenBuffers(1, &vboID);
	glGenBuffers(1, &iboID);

	// Sending data to the GPU
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * vertCount, vertices.data(), GL_STATIC_DRAW);

	unsigned int indices[] =
	{
			0,1,2,
			0,2,3
			
			

	
	};



	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void Mesh::Draw()
{
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(3 * sizeof(float)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(6 * sizeof(float)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	//glDrawArrays(GL_TRIANGLES, 0, 3); // This will probably be the only thing necessary in Draw()

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

}

void Mesh::FBDraw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(6 * sizeof(float)));
	
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}



