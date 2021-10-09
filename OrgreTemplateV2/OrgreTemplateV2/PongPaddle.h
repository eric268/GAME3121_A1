#pragma once

#include "GameObject.h"
class PongPaddle : public GameObject
{
private:
	float m_fBounds;
public:
	PongPaddle()
	{
		SetSceneNode(nullptr);
		SetEntity(nullptr);
		SetVelocity(Ogre::Vector3(0, 0, 0));
		SetSpeed(0.0f);
		m_fBounds = 0;
	}
	PongPaddle(Ogre::SceneNode* player, Ogre::SceneManager* scnMgr)
	{
		SetEntity(scnMgr->createEntity("Player1Entity", "cube.mesh"));
		GetEntity()->setCastShadows(false);

		SetSceneNode(player);
		GetSceneNode()->attachObject(GetEntity());
		scnMgr->getRootSceneNode()->addChild(GetSceneNode());

		GetSceneNode()->setScale(0.1f, 0.1f, 0.4f);
		GetSceneNode()->setPosition(Ogre::Vector3(-50, 0, 0));
		SetVelocity(Ogre::Vector3(0, 0, 0));
		SetSpeed(50.0f);
		m_fBounds = 110;
	}
	void BoundsChecking()
	{
		if (GetSceneNode()->getPosition().z <= -m_fBounds)
		{
			Ogre::Vector3 temp = GetSceneNode()->getPosition();
			GetSceneNode()->setPosition(Ogre::Vector3(temp.x, temp.y, -m_fBounds));
		}
		else if (GetSceneNode()->getPosition().z >= m_fBounds)
		{
			Ogre::Vector3 temp = GetSceneNode()->getPosition();
			GetSceneNode()->setPosition(Ogre::Vector3(temp.x, temp.y, m_fBounds));
		}
	}
	bool frameStarted(const Ogre::FrameEvent& evt)
	{
		GetSceneNode()->translate(GetVelocity() * evt.timeSinceLastFrame);
		BoundsChecking();

		return true;
	}
};


