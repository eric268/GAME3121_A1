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