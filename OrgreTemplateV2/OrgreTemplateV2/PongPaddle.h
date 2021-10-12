#pragma once

#include "GameObject.h"
class PongPaddle : public GameObject
{
private:
	float m_fBounds;
public:
	PongPaddle();
	PongPaddle(Ogre::SceneNode* player, Ogre::SceneManager* scnMgr);
	void BoundsChecking();
	bool frameStarted(const Ogre::FrameEvent& evt);
};


