#include "GameObject.h"

Ogre::Vector3 GameObject::GetVelocity()
{
	return m_vVelocity;
}
Ogre::SceneNode* GameObject::GetSceneNode()
{
	return m_sceneNode;
}
Ogre::Entity* GameObject::GetEntity()
{
	return m_mesh;
}
float GameObject::GetSpeed()
{
	return m_fSpeed;
}

Ogre::Vector3 GameObject::GetScale()
{
	return m_scale;
}

float GameObject::GetWeight()
{
	return m_weight;
}

//Setters
void GameObject::SetSceneNode(SceneNode* node)
{
	m_sceneNode = node;
}
void GameObject::SetEntity(Entity* en)
{
	m_mesh = en;
}
void GameObject::SetVelocity(Ogre::Vector3 vel)
{
	m_vVelocity = vel;
}
void GameObject::SetSpeed(float speed)
{
	m_fSpeed = speed;
}

void GameObject::SetScale(Ogre::Vector3 scale)
{
	m_scale = scale;
}

void GameObject::SetWeight(float weight)
{
	m_weight = weight;
}
