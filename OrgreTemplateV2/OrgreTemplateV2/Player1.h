#pragma once
#include "Ogre.h"
#include "OgreInput.h"
#include <iostream>


using namespace Ogre;
using namespace OgreBites;

class Player1 : public Ogre::FrameListener, public InputListener
{
private:
	Ogre::SceneNode* m_player1Node;
	Ogre::Vector3 m_vVelocity;
	Ogre::Entity* m_mesh;
	float m_fPaddleSpeed;

public:
	Player1()
	{
		m_player1Node = nullptr;
		m_mesh = nullptr;
		m_vVelocity = Ogre::Vector3(0, 0, 0);
		m_fPaddleSpeed = 0.0f;
		
	}
	Player1(Ogre::SceneNode* player, Ogre::Entity* entity, Ogre::SceneManager* scnMgr)
	{
		m_mesh = entity;
		m_mesh->setCastShadows(false);

		m_player1Node = player;
		m_player1Node->attachObject(m_mesh);
		scnMgr->getRootSceneNode()->addChild(GetSceneNode());

		m_player1Node->setScale(0.1f, 0.1f, 0.4f);
		m_player1Node->setPosition(Ogre::Vector3(-50, 0, 0));
		m_vVelocity = Ogre::Vector3(0, 0, 0);
		m_fPaddleSpeed = 50.0f;
	}
	bool frameStarted(const Ogre::FrameEvent& evt)
	{
		m_player1Node->translate(m_vVelocity * evt.timeSinceLastFrame);
		return true;
	}

	void SetVelocity(Ogre::Vector3 vel)
	{
		m_vVelocity = vel;

	}
	Ogre::Vector3 GetVelocity()
	{
		return m_vVelocity;
	}
	Ogre::SceneNode* GetSceneNode()
	{
		return m_player1Node;
	}
	Ogre::Entity* GetEntity()
	{
		return m_mesh;
	}
	float GetPaddleSpeed()
	{
		return m_fPaddleSpeed;
	}

};

