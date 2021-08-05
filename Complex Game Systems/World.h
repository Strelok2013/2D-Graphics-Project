#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "SpriteMesh.h"
#include "GraphicsManager.h"
#include "Light.h"
#include "Math.h"
#include "Util.h"

class World 
{
private:
	

	SpriteMesh spriteRenderMesh;

	FBQuad fbRenderMesh;
	glm::mat4 orthoGraphicView;
	glm::vec2 lightDirection;
	glm::vec3 otherLightDirection;

	GraphicsManager* graphicsManager;

	TextureManager texManager;
	
	std::map<std::string, Sprite*> sprites; 

public:
	


	World();
	~World();

	void LoadDiffuseTexture(std::string textureName, std::string diffuseFile); // Loads only a diffuse texture
	void LoadNormalTexture(std::string textureName, std::string normalFile); // Loads only a normal texture
	void LoadSpecTexture(std::string textureName, std::string specFile); // Loads only a specular texture
	void LoadDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile); // Loads a Diffuse, Normal and specular texture

	void ReplaceDiffuseTexture(std::string textureName, std::string diffuseFile); // Replaces a diffuse texture at the given string key
	void ReplaceNormalTexture(std::string textureName, std::string normalFile); // Replaces a normal texture at the given string key
	void ReplaceSpecTexture(std::string textureName, std::string specFile); // Replaces a specular texture at the given string key
	void ReplaceDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile); // Replaces diffuse, normal and specular textures at a given string key

	void CreateSprite(std::string spriteName, std::string textureName); // Create a sprite with a name and loaded texture name (texture name must match a texture loaded in)

	void SetLightDirection(glm::vec2 targetDir); // Sets the direction of the light (the direction the godrays go)

	void ToggleLightMap(std::string targetSprite); // Toggle whether the target sprite is considered to be a lightmap
	void ToggleOcclusionMap(std::string targetSprite); // Toggle whether the target sprite is considered to be an occlusion map

	void SetSpriteOffset(glm::vec2 targetOffset, std::string spriteName); // Changes the sprite's position on the screen

	void Render(); // Render the world
	void Update(); // Update positions of the sprites

};