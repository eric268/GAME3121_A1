#pragma once

#include "GameObject.h"
#include "PongPaddle.h"
#include "CollisionManager.h"
class PongBall : public GameObject
{
private:
	bool m_bIsColliding;
	Ogre::Vector3 m_vDirection;
	PongPaddle* m_paddleRef;
	float m_radius;
	

public:
	PongBall();
	PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr, PongPaddle* pRef);
	bool GetIsColliding();
	void SetIsColliding(bool colliding);
	bool frameStarted(const Ogre::FrameEvent& evt);
	void CheckBounds();
	void CollisionWithPaddle();
	float GetRadius();
	void SetRadius(float radius);
	void VelocityAfterPaddleCollision();
};

