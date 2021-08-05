#include "Framebuffer.h"
#include "ShaderProgram.h"
#include "SpriteMesh.h"

Framebuffer::Framebuffer(FBQuad* quadRef)
{
	quadReference = quadRef;

	// Actually creating the framebuffer (atleast the handle to which to attach stuff to)
	glGenFramebuffers(1, &fboID);
	glBindFramebuffer(GL_FRAMEBUFFER, fboID);

	// Creating an empty texture for the framebuffer
	glGenTextures(1, &sampleTexID);
	glBindTexture(GL_TEXTURE_2D, sampleTexID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1280, 720, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glBindTexture(GL_TEXTURE_2D, 0);

	// Attaching the texture to the framebuffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, sampleTexID, 0);


	glGenRenderbuffers(1, &rboID);
	glBindRenderbuffer(GL_RENDERBUFFER, rboID);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1280, 720);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboID);
	//glBindRenderbuffer(GL_RENDERBUFFER, 0);


	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "Framebuffer not created successfully" << std::endl;
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	glBindFramebuffer(fboID, 0);
}

Framebuffer::~Framebuffer()
{
	glDeleteTextures(1, &sampleTexID);
	glDeleteFramebuffers(1, &fboID);
	glDeleteRenderbuffers(1, &rboID);
}

void Framebuffer::BindBuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, fboID);
}
void Framebuffer::UnbindBuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	//glBindVertexArray(0);
}

void Framebuffer::BindBufferQuad()
{
	quadReference->BindFBQuad();
}

void Framebuffer::BindTexture(int texNumber)
{
	glActiveTexture(GL_TEXTURE0 + texNumber);
	glBindTexture(GL_TEXTURE_2D, sampleTexID);
}

void Framebuffer::Draw(ShaderProgram* shaderReference)
{
	shaderReference->UseShader();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(1);
}
