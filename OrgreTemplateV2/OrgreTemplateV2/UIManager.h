#pragma once
#include "OgreTrays.h"
#include "Ogre.h"
#include "OgreInput.h"
#include "PongBall.h"
#include "PongPaddle.h"


using namespace Ogre;
using namespace OgreBites;

class UIManager : public Ogre::FrameListener
{
private:
	OgreBites::TrayListener myTrayListener;

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
	UIManager();
	UIManager(OgreBites::TrayManager* mTrayMgr, PongPaddle* paddleRef, PongBall* ballRef);

	OgreBites::TrayListener GetTrayListener();

	OgreBites::Label* GetScoreLabel();
	OgreBites::Label* GetScore();
	OgreBites::Label* GetLivesLabel();
	OgreBites::Label* GetLives();
	OgreBites::Label* GetTimePerUpdateLabel();
	OgreBites::Label* GetTimePerUpdate();
	OgreBites::Label* GetFPSLabel();
	OgreBites::Label* GetFPS();

	void CalculateFPS(float deltaTime);

	float fpsCounter = 0.0f;
	float fpsTotal = 0.0f;
	float timer = 0.0f;

	void SetScoreLabel(OgreBites::Label* label);
	void SetScore(OgreBites::Label* label);
	void SetLivesLabel(OgreBites::Label* label);
	void SetLives(OgreBites::Label* label);

	bool frameStarted(const Ogre::FrameEvent& evt);
};

