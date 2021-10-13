#include "PongBall.h"

PongBall::PongBall()
{
	SetSceneNode(nullptr);
	SetEntity(nullptr);
	SetVelocity(Ogre::Vector3(0, 0, 0));
	SetSpeed(0.0f);
	m_bIsColliding = false;
	m_scale = Ogre::Vector3(0.1f, 0.1f, 0.1f);
	m_lifeLost = false;
}

PongBall::PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr)
{
	SetEntity(scnMgr->createEntity("BallEntity", "sphere.mesh"));
	GetEntity()->setCastShadows(false);

	SetSceneNode(node);
	GetSceneNode()->attachObject(GetEntity());
	scnMgr->getRootSceneNode()->addChild(GetSceneNode());
	m_scale = Ogre::Vector3(0.1f, 0.1f, 0.1f);
	GetSceneNode()->setScale(m_scale);
	GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
	SetVelocity(Ogre::Vector3(0, 0, 0));
	SetSpeed(0.0f);
	
	m_bIsColliding = false;
	m_lifeLost = false;
	
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

bool PongBall::GetLifeLost()
{
	return m_lifeLost;
}

void PongBall::SetLifeLost(bool lifeLost)
{
	m_lifeLost = lifeLost;
}
