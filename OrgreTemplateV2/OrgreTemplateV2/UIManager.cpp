#include "UIManager.h"
#include "iomanip"
#include <string>
UIManager::UIManager()
{

}

UIManager::UIManager(OgreBites::TrayManager* mT, PongPaddle* paddleRef, PongBall* ballRef)
{
	mTrayMgr = mT;
	m_paddleRef = paddleRef;
	m_ballRef = ballRef;

	

	SetScoreLabel(mTrayMgr->createLabel(TL_TOPLEFT, "Score", "Score:", 150));
	SetScore(mTrayMgr->createLabel(TL_TOPLEFT, "score", std::to_string(m_paddleRef->GetScore()), 150));
	SetLivesLabel(mTrayMgr->createLabel(TL_TOPLEFT, "Lives", "Lives:", 150));
	SetLives(mTrayMgr->createLabel(TL_TOPLEFT, "lives", std::to_string(m_paddleRef->GetLivesRemaining()), 150));

	m_FPSLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "FPS", "FPS:", 150);
	m_FPS = mTrayMgr->createLabel(TL_TOPRIGHT, "fps", std::to_string(0), 150);

	m_TimePerUpdateLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "Time/Update", "Time/Update:", 150);
	m_TimePerUpdate = mTrayMgr->createLabel(TL_TOPRIGHT, "time/update", std::to_string(0), 150);

	

	
}

OgreBites::TrayListener UIManager::GetTrayListener()
{
	return myTrayListener;
}

OgreBites::Label* UIManager::GetScoreLabel()
{
	return mScoreLabel;
}

OgreBites::Label* UIManager::GetScore()
{
	return mScore;;
}

OgreBites::Label* UIManager::GetLivesLabel()
{
	return mLivesLabel;
}

OgreBites::Label* UIManager::GetLives()
{
	return mLives;;
}

void UIManager::SetScoreLabel(OgreBites::Label* label)
{
	mScoreLabel = label;
}

void UIManager::SetScore(OgreBites::Label* label)
{
	mScore = label;
}

void UIManager::SetLivesLabel(OgreBites::Label* label)
{
	mLivesLabel = label;
}

void UIManager::SetLives(OgreBites::Label* label)
{
	mLives = label;
}
void UIManager::CalculateFPS(float deltaTime)
{
	timer += deltaTime;
	if (deltaTime != 0)
	{
		fpsTotal += 1.0f / deltaTime;
	}
	fpsCounter++;

	if (timer >= 1)
	{
		float finalFPS = fpsTotal / fpsCounter;
		m_FPS->setCaption(std::to_string(finalFPS));
		timer = 0.0f;
		fpsTotal = 0.0f;
		fpsCounter = 0.0f;
	}
}

bool UIManager::frameStarted(const Ogre::FrameEvent& evt)
{
	if (m_paddleRef->GetPointEarned())
	{
		mScore->setCaption(std::to_string(m_paddleRef->GetScore()));
		m_paddleRef->SetPointEarned(false);
	}
	if (m_paddleRef->GetLifeLost())
	{
		mLives->setCaption(std::to_string(m_paddleRef->GetLivesRemaining()));
		m_paddleRef->SetLifeLabel(false);
	}

	CalculateFPS(evt.timeSinceLastFrame);
	m_TimePerUpdate->setCaption(std::to_string(evt.timeSinceLastFrame) + " ms");


	return true;
}
