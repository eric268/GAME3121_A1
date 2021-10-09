#pragma once
#include "Ogre.h"
#include "OgreInput.h"
#include <iostream>


using namespace Ogre;
using namespace OgreBites;

class GameObject : public Ogre::FrameListener
{
private:
	Ogre::SceneNode* m_sceneNode;
	Ogre::Vector3 m_vVelocity;
	Ogre::Entity* m_mesh;
	float m_fSpeed;

public:
	//Getters
	Ogre::Vector3 GetVelocity()
	{
		return m_vVelocity;
	}
	Ogre::SceneNode* GetSceneNode()
	{
		return m_sceneNode;
	}
	Ogre::Entity* GetEntity()
	{
		return m_mesh;
	}
	float GetSpeed()
	{
		return m_fSpeed;
	}

	//Setters
	void SetSceneNode(SceneNode* node)
	{
		m_sceneNode = node;
	}
	void SetEntity(Entity* en)
	{
		m_mesh = en;
	}
	void SetVelocity(Ogre::Vector3 vel)
	{
		m_vVelocity = vel;
	}
	void SetSpeed(float speed)
	{
		m_fSpeed = speed;
	}
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
};
