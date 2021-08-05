#include "Light.h"

DirectionalLight::DirectionalLight()
{
	direction = { -0.5f, -1.0f, -0.5f };
	lightColor = { 1.0f, 1.0f, 1.0f };
}