#pragma once

#include "GameObject.h"
class PongBall : public GameObject
{
private:
	bool m_bIsColliding;
	Ogre::Vector3 m_vDirection;

public:
	PongBall()
	{
		SetSceneNode(nullptr);
		SetEntity(nullptr);
		SetVelocity(Ogre::Vector3(0, 0, 0));
		SetSpeed(0.0f);
	}
	PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr)
	{
		SetEntity(scnMgr->createEntity("BallEntity", "sphere.mesh"));
		GetEntity()->setCastShadows(false);

		SetSceneNode(node);
		GetSceneNode()->attachObject(GetEntity());
		scnMgr->getRootSceneNode()->addChild(GetSceneNode());

		GetSceneNode()->setScale(0.1f, 0.1f, 0.1f);
		GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
		SetVelocity(Ogre::Vector3(0, 0, 0));
		SetSpeed(0.0f);
		m_bIsColliding = false;
	}
	bool GetIsColliding()
	{
		return m_bIsColliding;
	}
	void SetIsColliding(bool colliding)
	{
		m_bIsColliding = colliding;
	}
	bool frameStarted(const Ogre::FrameEvent& evt)
	{
		GetSceneNode()->translate(GetVelocity() * evt.timeSinceLastFrame);
		return true;
	}
};

