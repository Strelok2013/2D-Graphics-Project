#include "World.h"

World::World()
{
	float aspectRatio = 16 / 9.0f;

	otherLightDirection = { -0.5f, -1.0f, -0.5f };

	graphicsManager = new GraphicsManager(&fbRenderMesh);

	orthoGraphicView = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
}
World::~World()
{
	delete graphicsManager;

	for (std::pair<std::string, Sprite*> spr : sprites)
	{
		delete spr.second;
	}

}

void World::LoadDiffuseTexture(std::string textureName, std::string diffuseFile)
{
	texManager.LoadDiffuseTexture(textureName, diffuseFile);
}

void World::LoadNormalTexture(std::string textureName, std::string normalFile)
{
	texManager.LoadNormalTexture(textureName, normalFile);
}

void World::LoadSpecTexture(std::string textureName, std::string specFile)
{
	texManager.LoadSpecularTexture(textureName, specFile);
}

void World::LoadDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile)
{
	texManager.LoadDNSTexture(textureName, diffuseFile, normalFile, specFile);
}

void World::ReplaceDiffuseTexture(std::string textureName, std::string diffuseFile)
{
	texManager.ReplaceDiffuseTexture(textureName, diffuseFile);
}

void World::ReplaceNormalTexture(std::string textureName, std::string normalFile)
{
	texManager.ReplaceNormalTexture(textureName, normalFile);
}

void World::ReplaceSpecTexture(std::string textureName, std::string specFile)
{
	texManager.ReplaceSpecularTexture(textureName, specFile);
}

void World::ReplaceDNSTexture(std::string textureName, std::string diffuseFile, std::string normalFile, std::string specFile)
{
	texManager.ReplaceDNSTexture(textureName, diffuseFile, normalFile, specFile);
}

void World::CreateSprite(std::string spriteName, std::string textureName)
{
	Sprite* newSprite = new Sprite(&spriteRenderMesh);

	newSprite->DiffuseTexture(&texManager, textureName);
	newSprite->NormalTexture(&texManager, textureName);
	newSprite->SpecularTexture(&texManager, textureName);

	std::pair<std::string, Sprite*> spriteToBeAdded(spriteName, newSprite);

	sprites.insert(spriteToBeAdded);
}


void World::Render()
{

	// There should be a bunch of for loops that iteratge through all the sprites and check whether they are occlusion map sprite or not.
	/*
	* So like something like this:
	* for (Sprite spr in sprites)
	* {
	*	if(sprite.lightMap)
	*	{
	*		 Run the lightMap pass to render the lightMap and store it in the lightMap buffer
	*	}
	* 
	* Repeat for susbsequent passes...
	* }
	*/

	// Standard Pass
	graphicsManager->GetStandardShader()->SetUniform("lightDirection", otherLightDirection);
	graphicsManager->StandardPass();
	for (std::pair<std::string, Sprite*> spr : sprites)
	{
		if (!spr.second->IsLightMap() && !spr.second->IsOcclusionMap())
		{
			spr.second->BindSprite();
			spr.second->Draw(graphicsManager->GetStandardShader());

		}
	}

	// LightMap Pass
	glClearColor(0, 0, 0, 0);
	graphicsManager->LightPass();
	for (std::pair<std::string, Sprite*> spr : sprites)
	{
		if (spr.second->IsLightMap() && !spr.second->IsOcclusionMap())
		{
			spr.second->BindSprite();
			spr.second->Draw(graphicsManager->GetLightMapShader());
		}
	}

	// Occlusion Pass
	glClearColor(1, 1, 1, 1);
	graphicsManager->GetPostProcessShader()->SetUniform("lightDirection", lightDirection);
	graphicsManager->OcclusionPass();
	for(std::pair<std::string, Sprite*> spr : sprites)
	{
		if (!spr.second->IsLightMap() && spr.second->IsOcclusionMap())
		{
			spr.second->BindSprite();
			spr.second->Draw(graphicsManager->GetOcclusionShader());
		}
	}

	// Postprocess Pass
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	graphicsManager->PostProcessPass();
	glDisable(GL_DEPTH_TEST);
}

void World::Update()
{
	for (std::pair<std::string, Sprite*> spr : sprites)
	{
		spr.second->Update(orthoGraphicView);
	}
}

void World::ToggleLightMap(std::string targetSprite)
{
	sprites.at(targetSprite)->ToggleLightMap();
}

void World::ToggleOcclusionMap(std::string targetSprite)
{
	sprites.at(targetSprite)->ToggleOcclusionMap();
}

void World::SetLightDirection(glm::vec2 targetDir)
{
	lightDirection = targetDir;
}

void World::SetSpriteOffset(glm::vec2 targetOffset, std::string spriteName)
{
	sprites.at(spriteName)->SetSpriteOffset(targetOffset);
}