#include "TextureManager.h"

void TextureManager::LoadDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile)
{
	DNSTexture* textureToBeAdded = new DNSTexture();
	textureToBeAdded->diffuse = Texture(diffuseFile);
	textureToBeAdded->normal = Texture(normalFile);
	textureToBeAdded->specular = Texture(specFile);


	dnsTextures.insert(std::pair<std::string, DNSTexture*>(textureName, textureToBeAdded));

	/*This will delete every texture that's contained
	for (std::pair<std::string, DNSTexture*> thisPair : dnsTextures)
	{
		delete thisPair.second;
	}*/
}

TextureManager::~TextureManager()
{
	for (std::pair<std::string, DNSTexture*> currentPair : dnsTextures)
	{
		delete currentPair.second;
	}
}

void TextureManager::ReplaceDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile)
{
	DNSTexture* replacementTexture = new DNSTexture;
	
	replacementTexture->diffuse = diffuseFile;
	replacementTexture->normal = normalFile;
	replacementTexture->specular = specFile;

	dnsTextures.insert_or_assign(textureName, replacementTexture);
}


void TextureManager::LoadDiffuseTexture(std::string textureName, std::string diffuseFile)
{
	DNSTexture* textureToBeAdded = new DNSTexture();

	textureToBeAdded->diffuse = Texture(diffuseFile);

	dnsTextures.insert(std::pair<std::string, DNSTexture*>(textureName, textureToBeAdded));
}

void TextureManager::ReplaceDiffuseTexture(std::string targetTextureName, std::string diffuseFile)
{
	dnsTextures.at(targetTextureName)->diffuse = Texture(diffuseFile);
}

void TextureManager::LoadNormalTexture(std::string textureName, std::string normalFile)
{
	DNSTexture* textureToBeAdded = new DNSTexture();
	textureToBeAdded->normal = Texture(normalFile);

	dnsTextures.insert(std::pair<std::string, DNSTexture*>(textureName, textureToBeAdded));
}

void TextureManager::ReplaceNormalTexture(std::string textureName, std::string normalFile)
{
	dnsTextures.at(textureName)->normal = Texture(normalFile);
}

void TextureManager::LoadSpecularTexture(std::string textureName, std::string specFile)
{
	DNSTexture* textureToBeAdded = new DNSTexture();

	textureToBeAdded->specular = Texture(specFile);

	dnsTextures.insert(std::pair<std::string, DNSTexture*>(textureName, textureToBeAdded));
}

void TextureManager::ReplaceSpecularTexture(std::string textureName, std::string specFile)
{
	dnsTextures.at(textureName)->specular = Texture(specFile);
}


DNSTexture::~DNSTexture()
{
	
}
