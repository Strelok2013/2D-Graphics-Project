#pragma once
#include "Texture.h"
#include <map>
//class Texture;

struct DNSTexture
{
	Texture diffuse;
	Texture normal;
	Texture specular;
	DNSTexture() {};
	~DNSTexture();

};

class TextureManager
{
	friend class Sprite;

private:

	std::map<std::string, DNSTexture*> dnsTextures;
	
public:

	
	TextureManager() {};
	~TextureManager(); // Runs through all the textures in the map and deletes them (assuming there is something to delete)


	void LoadDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile); // Loads 3 textures into the loadedTextures array and add them to the end
	void ReplaceDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile); // Replaces 3 textures at the given index in the loadedTextures array
	void LoadDiffuseTexture(std::string textureName, std::string diffuseFile); // Load a new diffuse and push that to the end of the DNS (ONLY the diffuse will be added to the DNS, all other textures will be empty)
	void ReplaceDiffuseTexture(std::string textureName, std::string diffuseFile); // Replace the diffuse of a DNS at a specified index
	void LoadNormalTexture(std::string textureName, std::string normalFile); // Load a new normal and push that to the end of the DNS (ONLY the normal will be added to the DNS, all other textures will be empty)
	void ReplaceNormalTexture(std::string textureName, std::string normalFile); // Replace the normal of a DNS at a specified index
	void LoadSpecularTexture(std::string textureName, std::string specFile); // Load a new specular and push that to the end of the DNS (ONLY the specular will be added to the DNS, all other textures will be empty)
	void ReplaceSpecularTexture(std::string textureName, std::string specFile); // Replace the specular of a DNS at a specified index
};