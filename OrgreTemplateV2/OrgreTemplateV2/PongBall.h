#pragma once

#include "GameObject.h"
class PongBall : public GameObject
{
private:
	bool m_bIsColliding;
	Ogre::Vector3 m_vDirection;

public:
	PongBall();
	PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr);
	bool GetIsColliding();
	void SetIsColliding(bool colliding);
	bool frameStarted(const Ogre::FrameEvent& evt);
};

