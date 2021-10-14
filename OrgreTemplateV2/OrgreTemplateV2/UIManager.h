#pragma once
#include "OgreTrays.h"
#include "Ogre.h"
#include "OgreInput.h"
#include "PongBall.h"
#include "PongPaddle.h"
#include "CollisionManager.h"

using namespace Ogre;
using namespace OgreBites;

/// Encapsulates and manages all UI labels elements.
/// 
/// This class manages and updates all UI labels and elements. It uses references from the ball and player paddle to known when to update certain labels. It inherits from the Ogre::FrameListener class.
class UIManager : public Ogre::FrameListener
{
private:

	float fpsCounter = 0.0f;
	float fpsTotal = 0.0f;
	float timer = 0.0f;

	//Labels
	OgreBites::Label* mScoreLabel;
	OgreBites::Label* mScore;

	OgreBites::Label* mLivesLabel;
	OgreBites::Label* mLives;

	OgreBites::Label* m_FPSLabel;
	OgreBites::Label* m_FPS;

	OgreBites::Label* m_TimePerUpdateLabel;
	OgreBites::Label* m_TimePerUpdate;


	PongPaddle* m_paddleRef;
	PongBall* m_ballRef;

	OgreBites::TrayManager* mTrayMgr;
public:
	/// UIManager Constructor
	/// 
	/// This is the default constructor
	UIManager();

	/// UIManager Overloaded Constructor
	/// 
	/// This creates and initializes all labels as well as takes in references to the TrayManager, Paddle, and ball game objects.
	/// @param mTrayMgr This is a reference to the TrayManager created in the Main.cpp file. This allows for the UI elements to be displayed to the correct viewport.
	/// @param paddleRef This is a reference to the player paddle game object. This allows for checking if UI updates need to be done such as changing the score.
	/// @param ballRef This is a reference to the player paddle game object. This allows for checking if UI updates need to be done such as if the ball has gone past the protected area and a life has been lost.
	UIManager(OgreBites::TrayManager* mTrayMgr, PongPaddle* paddleRef, PongBall* ballRef);

	/// UIManager Destructor
	///
	/// This destroys all pointers to variables owned or managed by the UIManager. Specifically, all labels are owned by the UIManager.
	/// @note While the paddleRef and ballRef pointers are set to nullptr in this destructor the references are not destroyed here are they are owned by the MainInitializer class in main.cpp 
	~UIManager();

	/// Returns the Label pointer for the Score text box UI element.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetScoreLabel();

	/// Returns the Label pointer for the score integer value.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetScore();

	/// Returns the Label for the Lives Remaining text box UI element.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetLivesLabel();

	/// Returns the Label pointer for the score integer value.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetLives();

	/// Returns the Label pointer for the Time/Update text box UI element.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetTimePerUpdateLabel();

	/// Returns the Label for the Time/Update floating point value.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetTimePerUpdate();

	/// Returns the Label for the Frame Per Second text box UI element.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetFPSLabel();

	/// Returns the Label for the Frame Per Second point value.
	/// @returns Returns an OgreBites::Label Pointer
	OgreBites::Label* GetFPS();

	/// Calculates the Frames Per Second
	/// 
	/// Receives the amount of time since last frame and calculates the current update time per frame. Then averages the update time per frame across all updates within a second. 
	/// @param deltaTime provides the time since the last frame was updated. This is used to calculate the average frames updated in a second.
	void CalculateFPS(float deltaTime);

	/// Changes the Score Labels label
	/// 
	/// Allows for the Score Label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the score label will be set too.
	void SetScoreLabel(OgreBites::Label* label);

	/// Changes the numeric Score Labels label
	/// 
	/// Allows for the numeric score Label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the numeric score label will be set too.
	void SetScore(OgreBites::Label* label);

	/// Changes the lives remaining labels label
	/// 
	/// Allows for the lives remaining to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the lives remiaining label will be set too.
	void SetLivesLabel(OgreBites::Label* label);

	/// Changes the numeric lives remaining labels label
	/// 
	/// Allows for the numeric lives remaining to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the numeric lives remiaining label will be set too.
	void SetLives(OgreBites::Label* label);

	/// Changes the TimePerUpdate label
	/// 
	/// Allows for the TimePerUpdate label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the TimePerUpdate label will be set too.
	void SetTimePerUpdateLabel(OgreBites::Label* label);

	/// Changes the numeric TimePerUpdate label
	/// 
	/// Allows for the numeric TimePerUpdate label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the numeric TimePerUpdate label will be set too.
	void SetTimePerUpdate(OgreBites::Label* label);

	/// Changes the FPS Labels label
	/// 
	/// Allows for the FPS label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the FPS label will be set too.
	void SetFPSLabel(OgreBites::Label* label);

	/// Changes the FPS Labels label
	/// 
	/// Allows for the FPS label to be initialized or set to different labels.
	/// @param label is the OgreBites::Label pointer value the FPS label will be set too.
	void SetFPS(OgreBites::Label* label);

	/// Overrides the bool GameObject::frameStarted(const Ogre::FrameEvent& evt) function found in GameObject.h
	/// 
	/// Checks for updates at the beginning of each frame for the UI Manager. Is updates at a constant time across all hardware.
	/// @param evt Provides information regarding the time since the last event and the time since last update for the UIMangager.
	/// @returns Returns true if next frame should be updated and false if next frame should not be updated and the game should be exited.
	bool frameStarted(const Ogre::FrameEvent& evt);
};

