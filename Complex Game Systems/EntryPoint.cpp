#include "TestingZone.h"
#include "Sprite.h"
#include "Light.h"
#include "Framebuffer.h"
#include "TextureManager.h"
#include "SpriteMesh.h"
#include "World.h"



int main(void)
{
	GLFWwindow* window;

	float aspectRatio = 16 / 9.0f;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(1280, 720, "100% Original, again", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGL())
	{
		return -1;
	}
	

	//mesh->CreatePoint({ 0,0,0 });
	//mesh->CreateTriangle({-1.0f, -1.0f, 0.0f}, {1.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f});

	World world;

	//TestingClass testClass;
	//ShaderProgram standardRenderer; // Does the standard colors
	//ShaderProgram lightMapRenderer; // Does the lightmaps from which lighting is calculated
	//ShaderProgram occlusionRenderer; // Does the opaque blocks through which light cannot go through
	//ShaderProgram postProcess; // Does the final render pass to which everything is rendered to one quad filling the screen
	
	//TextureManager texManager;
	

	glm::vec2 offset1 = { 1.1f, 0.38f };
	glm::vec2 offset2 = { 0.1f, 0.1f };


	//SpriteMesh defaultMesh;
	//FBQuad defaultFBQuad;
	//
	//Framebuffer standard(&defaultFBQuad);
	//Framebuffer lightMapBuffer(&defaultFBQuad);
	//Framebuffer occlusionMapBuffer(&defaultFBQuad);
	//Framebuffer postProcessBuffer(&defaultFBQuad);
	//
	//Sprite sprite1(&defaultMesh);
	//Sprite sprite2(&defaultMesh);
	//Sprite sprite3(&defaultMesh);
	//
	//std::vector<ConstructorDemo> demos;
	//ConstructorDemo a, b;
	//a = std::move(b);
	//
	//demos.push_back(ConstructorDemo());
	//demos.push_back(ConstructorDemo());
	//demos.push_back(ConstructorDemo());
	//demos.push_back(ConstructorDemo());
	//
	//demos[1] = demos[2]; 

	world.LoadDNSTexture("ExampleHead", "ExampleHead_Diffuse.png", "ExampleHead_Normal.png", "ExampleHead_Specular.png");
	world.LoadDiffuseTexture("LightMap", "Light.png");
	world.LoadDiffuseTexture("OcclusionMap", "stonewall2_Diffuse.png");

	//texManager.LoadDNSTexture("ExampleHead","ExampleHead_Diffuse.png", "ExampleHead_Normal.png", "ExampleHead_Specular.png");
	//texManager.LoadDiffuseTexture("LightMap", "Light.png");
	//texManager.LoadDiffuseTexture("OcclusionMap", "stonewall2_Diffuse.png");

	DirectionalLight light;

 	glEnable(GL_DEPTH_TEST);

	//mesh->CreatePoint({ -0.5f, -0.5f, 0 });
	//mesh->CreatePoint({ 0.0f, 0.0f, 1.0f });
	//mesh->CreatePoint({ 0.5f, -0.5f, 0 });
	//mesh->CreatePoint({ 0.0f, 0.5f, 0.0f});


	glm::mat4 mat4(1);

	float time = 0;
	
	world.CreateSprite("Sprite1", "ExampleHead");

	world.CreateSprite("LightSprite", "LightMap");

	world.CreateSprite("OcclusionSprite", "OcclusionMap");

	world.ToggleLightMap("LightSprite");

	world.ToggleOcclusionMap("OcclusionSprite");

	world.SetLightDirection({ 1, 1 });

	//sprite1.DiffuseTexture(&texManager, "ExampleHead");
	//sprite1.NormalTexture(&texManager, "ExampleHead");
	//sprite1.SpecularTexture(&texManager, "ExampleHead");
	//sprite1.SetSpriteOffset({ -1.1, -0.5f });
	//
	//sprite2.DiffuseTexture(&texManager, "LightMap");
	//sprite2.SetSpriteOffset({ 1.1f, 0.38f });
	//
	//sprite3.DiffuseTexture(&texManager, "OcclusionMap");
	//sprite3.SetSpriteOffset({ 0.1f, 0.1f });

	//standard.CreateFBQuad();
	//lightMapBuffer.CreateFBQuad();
	//fb1.CreateFBQuad();
	//lightMapBuffer.CreateFBQuad();
	//postProcessBuffer.CreateFBQuad();


	//standardRenderer.CompileShaders("Standard.vsd", "Standard.fsd"); // Standard renderer has diffuse, normal and specular. Might want to change that later after getting the light map working
	//lightMapRenderer.CompileShaders("LightMap.vsd", "LightMap.fsd");
	//occlusionRenderer.CompileShaders("Occlusion.vsd", "Occlusion.fsd");
	//postProcess.CompileShaders("PostProcess.vsd", "PostProcess.fsd");
	//
	//standardRenderer.SetUniform("diffuse", 0);
	//standardRenderer.SetUniform("normal", 1);
	//standardRenderer.SetUniform("specular", 2);
	//
	//standardRenderer.SetUniform("lightDirection", light.GetLightDirection());
	//standardRenderer.SetUniform("lightColor", light.GetLightColor());
	//
	//
	//lightMapRenderer.SetUniform("lightTexture", 0);
	//
	//postProcess.SetUniform("standardPassTex", 0);
	//postProcess.SetUniform("lightMapPassTex", 1);
	//postProcess.SetUniform("occlusionMapPassTex", 2);
	//
	//
	//glm::mat4 view = glm::lookAt({ 0,0,0 }, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	//glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 100.0f);
	//glm::mat4 vpMatrix = projection * view;

	float moveSpeed = 0.009;
	


	//testClass.TestFunc();

	while (!glfwWindowShouldClose(window)) 
	{

		// Dumb vector/matrix maths that is not very relevant to the graphics stuff
		glm::vec3 translation = { glm::sin(time),glm::cos(time)* 0.5f,0 };
		glm::vec3 rotation = { 0, 0, 1 };
		glm::vec3 scale = { 0.5f, 0.5f, 0.5f };

		time += 0.0167f;
		
		glm::mat4 orthoGraphicView = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
		
		//diffuse.BindTexture(0);
		//normal.BindTexture(1);
		//specular.BindTexture(2);

		glm::mat4 translatedMat = glm::translate(mat4, translation);
		glm::mat4 scaledMat = glm::scale(mat4, scale);
		glm::mat4 rotatedMat = glm::rotate(mat4, time, rotation);
		glm::mat4 normalRotation = glm::rotate(mat4, time, rotation);
		glm::mat4 worldTransform = orthoGraphicView; //* rotatedMat;// *scaledMat;
	

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			offset1.y += moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			offset1.x -= moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			offset1.y -= moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			offset1.x += moveSpeed;
		}


		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			offset2.y += moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			offset2.x -= moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			offset2.y -= moveSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			offset2.x += moveSpeed;
		}



		world.SetSpriteOffset(offset1, "LightSprite");

		world.SetSpriteOffset(offset2, "OcclusionSprite");

		world.Update();
		world.Render();

		//sprite2.SetSpriteOffset(offset1);
		//
		//sprite3.SetSpriteOffset(offset2);


		


		//glEnable(GL_DEPTH_TEST); // Probably useless
		//
		//
		//
		//
		////standardRenderer.SetUniform("rotationMat", rotatedMat);
		////shaderManager->SetUniform("gScale", glm::sin(time));
		//
		//// Standard pass
		//standard.BindBuffer();
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//sprite1.BindSprite();
		//sprite1.Update(orthoGraphicView);
		//sprite1.Draw(&standardRenderer);
		//
		//// Lightmap pass
		//glClearColor(0, 0, 0, 0);
		//lightMapBuffer.BindBuffer();
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//sprite2.BindSprite();
		//sprite2.Update(orthoGraphicView);
		//sprite2.Draw(&lightMapRenderer);
		//
		//// Occlusion pass
		//glClearColor(1, 1, 1, 1);
		//occlusionMapBuffer.BindBuffer();
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//sprite3.BindSprite();
		//sprite3.Update(orthoGraphicView);
		//sprite3.Draw(&occlusionRenderer);
		////glClearColor(1, 1, 1, 1);
		////sprite3.BindSprite();
		////sprite3.Draw(&occlusionRenderer);
		//
		//occlusionMapBuffer.UnbindBuffer();
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		////postProcessBuffer.BindBuffer();
		//postProcessBuffer.BindBufferQuad();
		//standard.BindTexture(0);
		//lightMapBuffer.BindTexture(1);
		//occlusionMapBuffer.BindTexture(2);
		//postProcessBuffer.Draw(&postProcess);
		//
		//glClearColor(0, 0, 0, 0);
		//
		//
		//
		//glDisable(GL_DEPTH_TEST);


		// Final render pass happens here:
		//standard.UnbindBuffer();
		//standard.BindBufferQuad();
		//standard.BindTexture(0);
		//postProcess.UseShader();
		//
		//standard.Draw(&postProcess);

		//glClear(GL_COLOR_BUFFER_BIT); // Is this even needed here?


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();

	return 0;
}