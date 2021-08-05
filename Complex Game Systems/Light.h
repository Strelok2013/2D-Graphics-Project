#pragma once
#include "Math.h"

class DirectionalLight
{
private:

	glm::vec3 lightColor;
	glm::vec3 direction;

public:

	// Redundant class for now, ignore and don't use

	DirectionalLight();
	~DirectionalLight() {};

	glm::vec3 GetLightColor() { return lightColor; }
	glm::vec3 GetLightDirection() { return direction; }

};