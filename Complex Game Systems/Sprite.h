#pragma once
#include "Math.h"
#include "Graphics.h"
#include "Util.h"
#include "Texture.h"
#include "ShaderProgram.h"

class SpriteMesh;

class TextureManager;



class Sprite
{
private:
	SpriteMesh* meshReference;

	glm::vec2 offset = { 0,0 }; // May not be used anymore
	glm::vec3 color = { 1,1,1 }; // Used to tint the sprite a certain color


	glm::mat4 worldTransform; // Currently this is the only matrix that is used. The others are not used for anything yet so don't touch them
	glm::mat4 translationMat;
	glm::mat4 rotationMat;
	glm::mat4 scaleMat;

	// References to the textures used by the sprite (these are stored inside the TextureManager class)
	Texture* spriteDiffuse;
	Texture* spriteNormal;
	Texture* spriteSpecular;

	float rotation = 0; // Unused, similar to the other three matrices above

	// These bools are used to determine whether the sprite is a light map or occlusion map
	// Note: A sprite cannot have both a light map and an occlusion map.
	bool lightMap;
	bool occlusionMap;
	

public:

	

	Sprite(SpriteMesh* sptMeshReference);

	void BindSprite(); // Binds the sprite and its textures + mesh for drawing
	void Draw(ShaderProgram* shaderReference); // Draws the sprite using a specific shader
	void Update(glm::mat4 projectionMat); // Updates the sprite's position using the offset
	~Sprite();


	void DiffuseTexture(TextureManager* managerReference, std::string textureName); // Sets the sprites diffuse texture
	void NormalTexture(TextureManager* managerReference, std::string textureName); // Sets the sprites normal texture
	void SpecularTexture(TextureManager* managerReference, std::string textureName);//  Sets the sprites specular texture

	void SetSpriteColor(glm::vec3 targetColor); // Sets the sprites offset
	void SetSpriteOffset(glm::vec2 targetOffset); // This does nothing for now. Do not use

	void ToggleLightMap(); // Toggles whether the sprite is a lightmap (WARNING! if occlusion Map is on, then it will be toggled off upon calling this function)
	void ToggleOcclusionMap(); // Toggles whether the sprite is an occlusionMap (WARNING! if lightmap is on, then it will be toggled off upon calling this function);

	bool IsLightMap() { return lightMap; } // Simple get function to get whether or not the sprite is a light map
	bool IsOcclusionMap() { return occlusionMap; } // Simple get function to get whether or not the sprite is a occlusion map

	// Copy/assign operators potentially needed



};