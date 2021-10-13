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
	Ogre::Vector3 m_scale;
	float m_weight;

public:
	//Getters
	Ogre::Vector3 GetVelocity();
	Ogre::SceneNode* GetSceneNode();
	Ogre::Entity* GetEntity();
	float GetSpeed();
	Ogre::Vector3 GetScale();
	float GetWeight();

	//Setters
	void SetSceneNode(SceneNode* node);
	void SetEntity(Entity* en);
	void SetVelocity(Ogre::Vector3 vel);
	void SetSpeed(float speed);
	void SetScale(Ogre::Vector3 scale);
	void SetWeight(float weight);
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
};
