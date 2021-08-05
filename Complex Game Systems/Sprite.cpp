#include "Sprite.h"
#include "SpriteMesh.h"
#include "TextureManager.h"

Sprite::Sprite(SpriteMesh* sptMeshReference)
{
	glm::mat4  standardMat4 = glm::mat4(1);

	meshReference = sptMeshReference;

	worldTransform = glm::mat4(1);
	translationMat = glm::translate(standardMat4, { offset ,0 });
	rotationMat = glm::rotate(standardMat4, 0.0f, { 0,0,1 });
	scaleMat = glm::scale(standardMat4, { 1,1,1 });


}

Sprite::~Sprite()
{
	spriteDiffuse = nullptr;
	spriteNormal = nullptr;
	spriteSpecular = nullptr;
	meshReference = nullptr;
}

void Sprite::BindSprite()
{
	if (spriteDiffuse)
	{
		spriteDiffuse->BindTexture(0);
	}
	else
	{
	spriteDiffuse->UnbindTexture(0);
	}


	if (spriteNormal)
	{
		spriteNormal->BindTexture(1);
	}
	else
	{
		spriteNormal->UnbindTexture(1);
	}

	if (spriteSpecular)
	{
		spriteSpecular->BindTexture(2);
	}
	else
	{
		spriteSpecular->UnbindTexture(2);
	}

	meshReference->BindMesh();
}

void Sprite::Update(glm::mat4 projectionMat)
{

	glm::mat4  standardMat4 = glm::mat4(1);

	translationMat = glm::translate(standardMat4, { offset ,0 });
	rotationMat = glm::rotate(standardMat4, 0.0f, { 0,0,1 });
	scaleMat = glm::scale(standardMat4, { 1,1,1 });
	worldTransform = projectionMat * translationMat * rotationMat * scaleMat;
}

void Sprite::Draw(ShaderProgram* shaderReference)
{
	// The shader reference is there to indicate which shader to use to render the sprite
	shaderReference->SetUniform("WorldTransform", worldTransform);
	shaderReference->UseShader();
	glDrawElements(GL_TRIANGLES, meshReference->indexCount, GL_UNSIGNED_INT, 0);
}

void Sprite::DiffuseTexture(TextureManager* managerReference, std::string textureName)
{
	if (managerReference->dnsTextures.at(textureName)->diffuse.Exists())
	{
		spriteDiffuse = &managerReference->dnsTextures.at(textureName)->diffuse;
	}
	else
	{
		spriteDiffuse = nullptr;
	}
}

void Sprite::NormalTexture(TextureManager* managerReference, std::string textureName)
{
	if (managerReference->dnsTextures.at(textureName)->normal.Exists())
	{
		spriteNormal = &managerReference->dnsTextures.at(textureName)->normal;
	}
	else
	{
		spriteNormal = nullptr;
	}

}

void Sprite::SpecularTexture(TextureManager* managerReference, std::string textureName)
{
	if (managerReference->dnsTextures.at(textureName)->specular.Exists())
	{
		spriteSpecular = &managerReference->dnsTextures.at(textureName)->specular;
	}
	else
	{
		spriteSpecular = nullptr;
	}
}


void Sprite::SetSpriteColor(glm::vec3 targetColor)
{

}

void Sprite::SetSpriteOffset(glm::vec2 targetOffset)
{
	offset = targetOffset;
}

void Sprite::ToggleLightMap()
{
	if (occlusionMap)
	{
		occlusionMap = false;
	}
	if (!lightMap)
	{
		lightMap = true;
	}
	else
	{
		lightMap = false;
	}
}

void Sprite::ToggleOcclusionMap()
{
	if (lightMap)
	{
		lightMap = false;
	}
	if (!occlusionMap)
	{
		occlusionMap = true;
	}
	else
	{
		occlusionMap = false;
	}
}