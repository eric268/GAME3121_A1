#pragma once

#include "Ogre.h"
#include "GameObject.h"
using namespace Ogre;

class CollisionManager
{
public:
	static bool AABBSphere(GameObject* cube, GameObject* sphere);
};

