#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(FBQuad* bufferMeshReference)
{
	standardShader.CompileShaders("Standard.vsd", "Standard.fsd");
	lightMapShader.CompileShaders("LightMap.vsd", "LightMap.fsd");
	occlusionMapShader.CompileShaders("Occlusion.vsd", "Occlusion.fsd");
	postProcessShader.CompileShaders("PostProcess.vsd", "PostProcess.fsd");

	standardShader.SetUniform("diffuse", 0);
	standardShader.SetUniform("normal", 1);
	standardShader.SetUniform("specular", 2);

	lightMapShader.SetUniform("lightTexture", 0);

	postProcessShader.SetUniform("standardPassTex", 0);
	postProcessShader.SetUniform("lightMapPassTex", 1);
	postProcessShader.SetUniform("occlusionMapPassTex", 2);

	standardBuffer = new Framebuffer(bufferMeshReference);
	lightMapBuffer = new Framebuffer(bufferMeshReference);
	occlusionMapBuffer = new Framebuffer(bufferMeshReference);
	postProcessBuffer = new Framebuffer(bufferMeshReference);

}


void GraphicsManager::StandardPass()
{
	standardBuffer->BindBuffer();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsManager::LightPass()
{
	glClearColor(0, 0, 0, 0);
	lightMapBuffer->BindBuffer();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsManager::OcclusionPass()
{
	glClearColor(1, 1, 1, 1);
	occlusionMapBuffer->BindBuffer();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsManager::PostProcessPass()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	postProcessBuffer->BindBufferQuad();
	standardBuffer->BindTexture(0);
	lightMapBuffer->BindTexture(1);
	occlusionMapBuffer->BindTexture(2);
	postProcessBuffer->Draw(&postProcessShader);
	glClearColor(0, 0, 0, 0);
}

GraphicsManager::~GraphicsManager()
{
	delete standardBuffer;
	delete lightMapBuffer;
	delete occlusionMapBuffer;
	delete postProcessBuffer;
}