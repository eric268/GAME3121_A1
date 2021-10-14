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

	try
	{
		if (ball)
			radius = ball->GetRadius();
		else
		{
			std::bad_cast bC = std::bad_cast::__construct_from_string_literal("Failed to cast Game Object Sphere to Pong Ball in AABBSphere CollisionManager");
			throw bC;
		}

	}
	catch (const std::bad_cast& e)
	{
		std::cout << e.what() << '\n';
		exit(1);
	}

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

	//Square radius so that we don't have to take sqrt of distance. More optimized
	bool ans = distance < (radius* radius);

	if (ball)
	{
		ball->SetIsColliding(ans);
	}

	return ans;
}
