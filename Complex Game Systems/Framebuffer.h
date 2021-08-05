#pragma once
#include "Math.h"
#include "Graphics.h"
#include "Util.h"

class ShaderProgram;
class FBQuad;

class Framebuffer
{

	struct FBVertex
	{
		glm::vec2 position;
		glm::vec2 uvs;
	};

private:
	GLuint fboID = -1;
	GLuint sampleTexID = -1;
	GLuint rboID = -1;

	FBQuad* quadReference;


public:

	Framebuffer(); // Does nothing, Do not use.
	Framebuffer(FBQuad* quadRef); // Creates a new framebuffer using a quad reference for binding and drawing to 
	~Framebuffer();
	Framebuffer(const Framebuffer& other) = delete; // Copy operator
	Framebuffer& operator= (const Framebuffer& other) = delete; // Assignment operator

	void CreateFBQuad();

	void Draw(ShaderProgram* shaderReference);

	void BindBuffer(); // Binds the buffer to capture a frame
	void UnbindBuffer(); // Unbinds the buffer to allow for other buffers to do stuff (or revert back to default buffer)
	void BindBufferQuad(); // Needed in the post process buffer
	void BindTexture(int texNumber); // Binds the framebuffers sample texture
	


};