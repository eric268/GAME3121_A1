#pragma once

#include "GameObject.h"

/// The class which controls all Pong Paddle functionality
/// 
/// This class encapsulates and updates all variables and functions associated with the Pong Paddle game object. It inherits from the Game Object class.
class PongPaddle : public GameObject
{
private:
	float m_fBounds;
	int m_iScore;
	int m_iLivesRemaining;

	bool m_lifeLost;
	bool m_pointEarned;
public:
	/// Default constructor for the PongPaddle.
	/// 
	/// Initializes all values to 0 or nullptr.
	PongPaddle();

	/// Overloaded constructor for the PongPaddle class.
	/// 
	/// This initializes and creates the player PongPaddle.
	/// @param player This takes in a SceneNode pointer to the scene node created for the player paddle.
	/// @param SceneManager* This takes in a reference to the SceneManager pointer found in the MainInitalizer class in main.cpp.
	PongPaddle(Ogre::SceneNode* player, Ogre::SceneManager* scnMgr);

	/// Destructor for the PongPaddle class.
	///
	~PongPaddle();

	/// Ensures the paddle stays within the screen bounds.
	/// 
	/// This function ensures that the paddle is unable to be moved past the screens boarder.
	void BoundsChecking();

	/// Returns the score of the game
	/// 
	/// @returns Returns an integer value.
	int GetScore();

	/// Returns how many lives are remaining.
	///  
	/// @returns Returns an integer value.
	int GetLivesRemaining();

	/// Returns whether or not a life has been lost.
	///  
	/// This is used by the UIManager to know when to update the numeric label for number of lives remaining. This boolean is then set to true inside of the UIManager when the label has been successfully updated.
	/// @returns Returns a boolean value.
	bool GetLifeLost();

	/// Returns whether or not the score should be updated.
	///  
	/// This is used by the UIManager to know when to update the numeric label for players score.
	/// @returns Returns a boolean value.
	bool GetPointEarned();

	/// Increases the current players score by 1.
	///
	void IncrementScore();

	/// Decreases the number of remaining lives by 1.
	/// 
	void DecrementLivesRemaining();

	/// Sets the current score
	/// 
	/// Initializes or sets the current score to the parameter.
	/// @param score is an integer that the current score will be set to.
	void SetScore(int score);

	/// Sets the number of remaining lives.
	/// 
	/// Initializes or sets the number of remaining lives to the parameter.
	/// @param livesRemaining is an integer that the current lives remaining will be set to.
	void SetLivesRemaining(int livesRemaining);

	/// Sets the booleans for score update checking
	///  
	/// This boolean is set to true when the score has changed which tells the UIManager to update the score label that is displayed. It is set back to false once the UIManager has successfully updated that label.
	/// @param pEarned is an integer that the update score boolean will be set to.
	void SetPointEarned(bool pEarned);

	/// Sets the booleans for checking if the life remaining label should be updated.
	///  
	/// This boolean is set to true when a life has been lost which tells the UIManager to update the number of lives remaining that is displayed. It is set back to false once the UIManager has successfully updated that label.
	/// @param pEarned is an integer that the update score boolean will be set to.
	void SetLifeLabel(bool lifeLost);

	/// Overrides the bool GameObject::frameStarted(const Ogre::FrameEvent& evt) function found in GameObject.h
	/// 
	/// Checks for updates at the beginning of each frame for all Pong Paddle objects. Is updates at a constant time across all hardware.
	/// @param evt Provides information regarding the time since the last event and the time since last update for each Pong Paddle object.
	/// @returns Returns true if next frame should be updated and false if next frame should not be updated and the game should be exited.
	bool frameStarted(const Ogre::FrameEvent& evt);
};


