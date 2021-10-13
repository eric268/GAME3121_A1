#pragma once

#include "GameObject.h"

class PongPaddle : public GameObject
{
private:
	float m_fBounds;
	int m_iScore;
	int m_iLivesRemaining;

	bool m_lifeLost;
	bool m_pointEarned;
public:
	PongPaddle();
	PongPaddle(Ogre::SceneNode* player, Ogre::SceneManager* scnMgr);
	void BoundsChecking();
	int GetScore();
	int GetLivesRemaining();
	bool GetLifeLost();
	void IncrementScore();
	void DecrementLivesRemaining();

	void SetScore(int score);
	void SetLivesRemaining(int livesRemaining);
	bool frameStarted(const Ogre::FrameEvent& evt);

	bool GetPointEarned();
	void SetPointEarned(bool pEarned);

	void SetLifeLabel(bool lifeLost);
};


