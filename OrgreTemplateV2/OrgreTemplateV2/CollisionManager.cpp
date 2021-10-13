#include "CollisionManager.h"
#include <iostream>
#include "algorithm"
#include "PongBall.h"
//#define DEBUG




bool CollisionManager::AABBSphere(GameObject* cube, GameObject* sphere)
{
	

	const float xCubeMin = cube->GetSceneNode()->getPosition().x - (50.0f * cube->GetScale().x);
	const float xCubeMax = cube->GetSceneNode()->getPosition().x + (50.0f * cube->GetScale().x);
	const float yCubeMin = cube->GetSceneNode()->getPosition().y - (50.0f * cube->GetScale().y);
	const float yCubeMax = cube->GetSceneNode()->getPosition().y + (50.0f * cube->GetScale().y);
	const float zCubeMin = cube->GetSceneNode()->getPosition().z - (50.0f * cube->GetScale().z);
	const float zCubeMax = cube->GetSceneNode()->getPosition().z + (50.0f * cube->GetScale().z);

	float radius = 0;
	PongBall* ball = dynamic_cast<PongBall*>(sphere);
	if (ball)
		radius = ball->GetRadius();

	else
		std::cout << "Cast to ball failed in Collision Check" << std::endl;


	float xSpherePos = sphere->GetSceneNode()->getPosition().x;
	float ySpherePos = sphere->GetSceneNode()->getPosition().y;
	float zSpherePos = sphere->GetSceneNode()->getPosition().z;

#ifdef DEBUG
	std::cout << "xMin: " << xMin << std::endl;
	std::cout << "xMax: " << xMax << std::endl;
	std::cout << "yMin: " << yMin << std::endl;
	std::cout << "yMax: " << yMax << std::endl;
	std::cout << "zMin: " << zMin << std::endl;
	std::cout << "zMax: " << zMax << std::endl;
	std::cout << "Radius: " << radius << std::endl;
#endif // DEBUG
	
	float x = std::max(xCubeMin, std::min(xSpherePos, xCubeMax));
	float y = std::max(yCubeMin, std::min(ySpherePos, yCubeMax));
	float z = std::max(zCubeMin, std::min(zSpherePos, zCubeMax));
	
	float distance = (x - xSpherePos) * (x - xSpherePos) + (y - ySpherePos) * (y - ySpherePos) + (z - zSpherePos) * (z - zSpherePos);

	return distance < (radius* radius);
}
