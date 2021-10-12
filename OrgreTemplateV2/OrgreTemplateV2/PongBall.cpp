#include "PongBall.h"

PongBall::PongBall()
{
	SetSceneNode(nullptr);
	SetEntity(nullptr);
	SetVelocity(Ogre::Vector3(0, 0, 0));
	SetSpeed(0.0f);
	m_bIsColliding = false;
}

PongBall::PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr)
{
	SetEntity(scnMgr->createEntity("BallEntity", "sphere.mesh"));
	GetEntity()->setCastShadows(false);

	SetSceneNode(node);
	GetSceneNode()->attachObject(GetEntity());
	scnMgr->getRootSceneNode()->addChild(GetSceneNode());

	GetSceneNode()->setScale(0.1f, 0.1f, 0.1f);
	GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
	SetVelocity(Ogre::Vector3(0, 0, 0));
	SetSpeed(0.0f);

	m_bIsColliding = false;
}

bool PongBall::GetIsColliding()
{
	return m_bIsColliding;
}

void PongBall::SetIsColliding(bool colliding)
{
	m_bIsColliding = colliding;
}

bool PongBall::frameStarted(const Ogre::FrameEvent & evt)
{
	GetSceneNode()->translate(GetVelocity() * evt.timeSinceLastFrame);
	return true;
}