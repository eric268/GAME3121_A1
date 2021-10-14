#include "UIManager.h"
#include "iomanip"
#include <string>
UIManager::UIManager()
{
	mTrayMgr = nullptr;
	m_paddleRef = nullptr;
	m_ballRef = nullptr;

	mScoreLabel = nullptr;
	mScore = nullptr;

	mLivesLabel = nullptr;
	mLives = nullptr;
	m_FPSLabel = nullptr;
	m_FPS = nullptr;

	m_TimePerUpdateLabel = nullptr;
	m_TimePerUpdate = nullptr;
}

UIManager::UIManager(OgreBites::TrayManager* mT, PongPaddle* paddleRef, PongBall* ballRef)
{
	mTrayMgr = mT;
	m_paddleRef = paddleRef;
	m_ballRef = ballRef;

	mScoreLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Score", "Score:", 150);
	mScore = mTrayMgr->createLabel(TL_TOPLEFT, "score", std::to_string(m_paddleRef->GetScore()), 150);

	mLivesLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Lives", "Lives:", 150);
	mLives = mTrayMgr->createLabel(TL_TOPLEFT, "lives", std::to_string(m_paddleRef->GetLivesRemaining()), 150);

	m_FPSLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "FPS", "FPS:", 150);
	m_FPS = mTrayMgr->createLabel(TL_TOPRIGHT, "fps", std::to_string(0), 150);

	m_TimePerUpdateLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "Time/Update", "Time/Update:", 150);
	m_TimePerUpdate = mTrayMgr->createLabel(TL_TOPRIGHT, "time/update", std::to_string(0), 150);	
}
UIManager::~UIManager()
{
	delete mTrayMgr;
	mTrayMgr = nullptr;

	delete mScoreLabel;
	mScoreLabel = nullptr;

	delete mScore;
	mScore = nullptr;

	delete mLivesLabel;
	mLivesLabel = nullptr;

	delete mLives;
	mLives = nullptr;

	delete m_FPSLabel;
	m_FPSLabel = nullptr;

	delete m_FPS;
	m_FPS = nullptr;

	delete m_TimePerUpdateLabel;
	m_TimePerUpdateLabel = nullptr;

	delete m_TimePerUpdate;
	m_TimePerUpdate	= nullptr;

	m_paddleRef = nullptr;
	m_ballRef = nullptr;

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

OgreBites::Label* UIManager::GetTimePerUpdateLabel()
{
	return m_TimePerUpdateLabel;
}

OgreBites::Label* UIManager::GetTimePerUpdate()
{
	return m_TimePerUpdate;
}

OgreBites::Label* UIManager::GetFPSLabel()
{
	return m_FPSLabel;
}

OgreBites::Label* UIManager::GetFPS()
{
	return m_FPS;
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
void UIManager::SetTimePerUpdateLabel(OgreBites::Label* label)
{
	m_TimePerUpdateLabel = label;
}
void UIManager::SetTimePerUpdate(OgreBites::Label* label)
{
	m_TimePerUpdate = label;
}
void UIManager::SetFPSLabel(OgreBites::Label* label)
{
	m_FPSLabel = label;
}
void UIManager::SetFPS(OgreBites::Label* label)
{
	m_FPS = label;
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
	m_TimePerUpdate->setCaption(std::to_string(evt.timeSinceLastFrame * 1000) + " ms");


	return true;
}
