#pragma once
#include "ShaderProgram.h"
#include "Framebuffer.h"

class FBQuad;

class GraphicsManager
{
private:

	ShaderProgram standardShader;
	ShaderProgram lightMapShader;
	ShaderProgram occlusionMapShader;
	ShaderProgram postProcessShader;

	Framebuffer* standardBuffer = nullptr;
	Framebuffer* lightMapBuffer = nullptr;
	Framebuffer* occlusionMapBuffer = nullptr;
	Framebuffer* postProcessBuffer = nullptr;
public:

	GraphicsManager() {};
	GraphicsManager(FBQuad* bufferMeshReference);
	void StandardPass(); // Performs the standard pass (rendering diffuse, normal and specular)
	void LightPass(); // Performs the lightMap pass (rendering the lightMap buffer image)
	void OcclusionPass(); // Performs the occlusionMap pass (rendering the occlusion buffer image)
	void PostProcessPass(); // Performs the final render pass (renders the post process buffer using the previous 3 buffers)
	ShaderProgram* GetStandardShader() { return &standardShader; } // Returns a reference to the standardShader (used in the Render() function in world)
	ShaderProgram* GetLightMapShader() { return &lightMapShader; } // Returns a reference to the lightMapShader (used in the Render() function in world)
	ShaderProgram* GetOcclusionShader() { return &occlusionMapShader; } // Returns a reference to the occlusiohShader (used in the Render() function in world)
	ShaderProgram* GetPostProcessShader() { return &postProcessShader; } // Returns a reference to the postProcessShader (used in the Render() function in world)
	~GraphicsManager();


};