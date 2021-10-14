#pragma once
#include "Ogre.h"
#include "OgreInput.h"
#include <iostream>


using namespace Ogre;
using namespace OgreBites;

/// Parent class for all game objects
/// 
/// A pure virtual class which is inherited from by all game objects
/// Provides base variables and functionality to all game objects
/// @note Inherits from FrameListener class
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

	/// Returns game objects velocity.
	/// @returns Ogre::Vector3.
	Ogre::Vector3 GetVelocity();

	/// Returns game objects scene node variable.
	/// 
	/// The Scene node controls main functionality of game objects.
	/// Such functionality is getting and setting the game objects position.
	/// @returns SceneNode pointer.
	Ogre::SceneNode* GetSceneNode();

	/// Returns game objects entity variable.
	/// 
	/// The entity variable acts like the mesh of an object.
	/// This is where its bounding box, materials and more are controlled.
	/// @returns Entity pointer.
	Ogre::Entity* GetEntity();

	/// Returns the speed of the game object.
	/// 
	/// The speed is what is used with direction to calculate objects velocity.
	/// @returns floating point value.
	float GetSpeed();

	/// Returns the scale of the objects mesh.
	/// 
	/// The scale of the object is used to determine it's current bounding box size.
	/// This is especially important for collision detection .
	/// @see CollisionManager::AABBSphere(GameObject* cube, GameObject* sphere).
	/// @returns Ogre::Vector3 value.
	Ogre::Vector3 GetScale();

	/// Returns the weight of the object
	/// 
	/// This was initially used for detecting change in velocity when ball and paddle hit.
	/// Currently this is not important but still instantiated for future potential use.
	/// @returns Returns a floating number.
	float GetWeight();

	//Setters
	
	/// Sets the game objects scene node.
	/// 
	/// Allows for game objects to instantiate or change scene nodes.
	/// @param node is the Scene node that the game object will be set to.
	void SetSceneNode(SceneNode* node);

	/// Sets the game objects entity node.
	/// 
	/// Allows for game objects to instantiate or change entities.
	/// @param en is the entity that the game object will be set to.
	void SetEntity(Entity* en);

	/// Changes game objects velocity.
	/// 
	/// Allows for game objects velocity to be initialized or set to different values.
	/// @param vel is the Ogre::Vector3 velocity that the game object will be set to.
	void SetVelocity(Ogre::Vector3 vel);

	/// Changes game objects speed
	/// 
	/// Allows for game objects speed to be initialized or set to different values.
	/// @param speed is the floating point value the game objects speed will be set to.
	void SetSpeed(float speed);

	/// Changes the scale of the game object
	/// 
	/// Allows for the game objects scale to be initialized or set to different values.
	/// @param scale is the Ogre::Vector3 value that the game objects scale will be set to.
	/// @note This is very important for collision detection as changing the bounding box without changing the scale will result in inaccurate collision detection.
	/// @see CollisionManager::AABBSphere(GameObject* cube, GameObject* sphere).
	void SetScale(Ogre::Vector3 scale);

	/// Changes the game objects weight
	/// 
	/// Allows for the game objects weight to be initialized or set to different values
	/// @param weight is the floating point value the game objects weight will be set too.
	void SetWeight(float weight);

	/// Frame started updates game objects at each frame
	/// 
	/// Allows for changes to be implemented on game objects at the start of each frame.
	/// This is time independent therefore game objects will be updated consistently across all hardware
	/// @param evt is a FrameEvent reference which provides information such as time from last event and time from last frame.
	/// @returns returns true if next frame should be started and false if next frame should not start and game should exit.
	/// @note This is a pure virtual function as no game objects should be created. All future objects in game should start by inheriting from game objects.
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
};
