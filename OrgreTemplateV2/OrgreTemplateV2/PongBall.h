#pragma once

#include "GameObject.h"
#include "PongPaddle.h"
#include "CollisionManager.h"

/// The class which controls all Pong Ball functionality
/// 
/// This class encapsulates and updates all variables and functions associated with the pong ball game object. It inherits from the Game Object class.
class PongBall : public GameObject
{
private:
	bool m_bIsColliding;
	Ogre::Vector3 m_vDirection;
	PongPaddle* m_paddleRef;
	float m_radius;
	

public:
	//Constructor

	/// Default constructor for the PongBall game object.
	/// 
	PongBall();

	/// Overloaded constructor for the PongBall game object
	/// 
	/// This initializes all variables from either the inherited game object of PongBall specific variables.
	/// @param node This takes in a SceneNode pointer to the scene node created for the player paddle.
	/// @param scnMgr This takes in a reference to the SceneManager pointer found in the MainInitalizer class in main.cpp.
	/// @param pRef This is a PongPaddle reference that is used for collision detection between the player paddle and the ball.
	/// @note The ball is the game object that handles collision between the paddle and it's self. This is because their is no collision response for the paddle, only for the ball.
	PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr, PongPaddle* pRef);

	///PongBall Destructor
	///
	~PongBall();

	/// Returns whether or not the ball is colliding.
	/// 
	/// This value only returns true if the ball is colliding with the player paddle, and returns false when it is not.
	/// @returns Returns a boolean.
	bool GetIsColliding();

	/// Sets the isColliding ball variable.
	/// 
	/// Initializes or sets the isColliding ball variable to the parameter.
	/// @param colliding is a boolean that the isColliding ball variable will be set to.
	void SetIsColliding(bool colliding);

	/// Returns whether the radius of the PongBall game object.
	///
	/// @returns Returns a floating point value.
	float GetRadius();


	/// Sets the radius ball variable.
	/// 
	/// Initializes or sets the radius of the PongBall game object. This value is usually based upon the scale of the ball as well as its initial mesh extends.
	/// @param radius is a floating point value that ball radius variable will be set to.
	void SetRadius(float radius);

	/// Ensures the ball stays within the desired screen bounds
	/// 
	/// This function ensures that the ball will bounce off the top, left and right bounds of the window. If the ball falls into the protected area this function also returns it to its starting location and notifies the UIManager that it needs to update the remaining lives labels.
	void CheckBounds();

	/// This function is called when the ball collides with the paddle.
	/// 
	/// This function offsets any overlap between the colliding game objects. It then calls a VelocityAfterPaddleCollision() to update the balls velocity.
	/// @see VelocityAfterPaddleCollision()
	void CollisionWithPaddle();

	/// Updates ball velocity upon collision
	/// 
	/// This function is called when the ball collides with the paddle. This updates the ball's velocity based upon the velocity of the player paddle.
	void VelocityAfterPaddleCollision();

	/// Overrides the bool GameObject::frameStarted(const Ogre::FrameEvent& evt) function found in GameObject.h
	/// 
	/// Checks for updates at the beginning of each frame for all Pong Ball objects. Is updates at a constant time across all hardware.
	/// @param evt Provides information regarding the time since the last event and the time since last update for each Pong Ball objects.
	/// @returns Returns true if next frame should be updated and false if next frame should not be updated and the game should be exited.
	bool frameStarted(const Ogre::FrameEvent& evt);
};

