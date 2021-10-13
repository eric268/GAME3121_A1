#include "PongBall.h"

PongBall::PongBall()
{
	SetSceneNode(nullptr);
	SetEntity(nullptr);
	SetVelocity(Ogre::Vector3(0, 0, 0));
	SetSpeed(75.0f);
	m_bIsColliding = false;
	SetScale(Ogre::Vector3(0.1f, 0.1f, 0.1f));
	SetWeight(0.5f);
	m_radius = 100.0f * GetScale().x;
}

PongBall::PongBall(Ogre::SceneNode* node, Ogre::SceneManager* scnMgr, PongPaddle* pRef)
{
	SetEntity(scnMgr->createEntity("BallEntity", "sphere.mesh"));
	GetEntity()->setCastShadows(false);
	m_paddleRef = pRef;

	SetSceneNode(node);
	GetSceneNode()->attachObject(GetEntity());
	scnMgr->getRootSceneNode()->addChild(GetSceneNode());
	SetScale(Ogre::Vector3(0.1f, 0.1f, 0.1f));
	GetSceneNode()->setScale(GetScale());
	GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
	SetSpeed(75.0f);
	SetVelocity(Ogre::Vector3(0, 0, GetSpeed()));
	SetWeight(0.5f);
	m_radius = 100.0f * GetScale().x;
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

void PongBall::VelocityAfterPaddleCollision()
{
	
	Ogre::Vector3 paddelMomentum = m_paddleRef->GetWeight() * m_paddleRef->GetVelocity();
	Ogre::Vector3 ballMomentum = GetWeight() * GetVelocity();
	Ogre::Vector3 totalMomentum = paddelMomentum + ballMomentum;

	float totalMass = m_paddleRef->GetWeight() + GetWeight();


	Ogre::Vector3 newVelocity = totalMomentum / totalMass;

	SetVelocity(Ogre::Vector3(newVelocity.x, 0, newVelocity.z * -1));
	

}

void PongBall::CollisionWithPaddle()
{
	float overlap = (m_paddleRef->GetSceneNode()->getPosition().z - 50.0f * m_paddleRef->GetScale().z) - GetSceneNode()->getPosition().z - GetRadius();
	std::cout << overlap << std::endl;
	GetSceneNode()->setPosition(GetSceneNode()->getPosition().x, GetSceneNode()->getPosition().y, GetSceneNode()->getPosition().z + overlap);
	VelocityAfterPaddleCollision();
	m_paddleRef->IncrementScore();
	m_paddleRef->SetPointEarned(true);
}

float PongBall::GetRadius()
{
	return m_radius;
}

void PongBall::SetRadius(float radius)
{
	m_radius = radius;
}

bool PongBall::frameStarted(const Ogre::FrameEvent& evt)
{

	GetSceneNode()->translate(GetVelocity() * evt.timeSinceLastFrame);
	CheckBounds();
	if (m_paddleRef->GetLivesRemaining() <= 0)
	{
		GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
		SetVelocity(Ogre::Vector3(0, 0, 0));
	}

	if (CollisionManager::AABBSphere(m_paddleRef, this))
	{
		CollisionWithPaddle();
	}
	return true;
}

void PongBall::CheckBounds()
{
	float m_xBounds = 220;
	float m_zBounds = 165;
	
	if (GetSceneNode()->getPosition().x - GetRadius() <= -m_xBounds)
	{
		Ogre::Vector3 temp = GetSceneNode()->getPosition();
		float overlap = GetSceneNode()->getPosition().x - GetRadius() + m_xBounds;
		std::cout << "overlap: " << overlap << std::endl;
		GetSceneNode()->setPosition(Ogre::Vector3(GetSceneNode()->getPosition().x - overlap, temp.y, temp.z));
		SetVelocity(Ogre::Vector3(GetVelocity().x * -1, GetVelocity().y, GetVelocity().z));
	}
	else if (GetSceneNode()->getPosition().x + GetRadius() >= m_xBounds)
	{
		Ogre::Vector3 temp = GetSceneNode()->getPosition();
		float overlap = m_xBounds - GetSceneNode()->getPosition().x - GetRadius();
		std::cout << "overlap: " << overlap << std::endl;
		GetSceneNode()->setPosition(Ogre::Vector3(GetSceneNode()->getPosition().x + overlap, temp.y, temp.z));
		SetVelocity(Ogre::Vector3(GetVelocity().x * -1, GetVelocity().y, GetVelocity().z));
	}
	else if (GetSceneNode()->getPosition().z - GetRadius() <= -m_zBounds)
	{
		Ogre::Vector3 temp = GetSceneNode()->getPosition();
		float overlap = GetSceneNode()->getPosition().z - GetRadius() + m_zBounds;
		GetSceneNode()->setPosition(Ogre::Vector3(temp.x, temp.y, GetSceneNode()->getPosition().z - overlap));
		SetVelocity(Ogre::Vector3(GetVelocity().x, GetVelocity().y, GetVelocity().z * -1));
	}
	else if (GetSceneNode()->getPosition().z >= 200)
	{
		GetSceneNode()->setPosition(Ogre::Vector3(0, 0, 0));
		SetVelocity(Ogre::Vector3(0, 0, GetSpeed()));
		m_paddleRef->DecrementLivesRemaining();
		m_paddleRef->SetLifeLabel(true);
	}
}


