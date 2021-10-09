//Week3-7-InteractiveAnimationDemo
//We will create a WASD control for Sinbad 
//Now use the translate vector to translate the model, and keep in mind to use time - based and not frame - based movement
//Hooman Salamat


#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include <iostream>
#include "PongBall.h"
#include "PongPaddle.h"

using namespace Ogre;
using namespace OgreBites;

class OgreTutorial
	: public ApplicationContext
	, public InputListener
{
private:
	PongPaddle* m_player1Pong;
	PongBall*   m_ball;

	SceneManager* scnMgr;
	Root* root;
public:
	OgreTutorial();
	virtual ~OgreTutorial() {}

	void setup();
	bool keyPressed(const KeyboardEvent& evt);
	bool keyReleased(const KeyboardEvent& evt);
	void createScene();
	void createCamera();
	void createFrameListener();
};


OgreTutorial::OgreTutorial()
	: ApplicationContext("week3-7-InteractiveAnimationDemo")
{
}


void OgreTutorial::setup()
{
	// do not forget to call the base first
	ApplicationContext::setup();
	addInputListener(this);
	

	// get a pointer to the already created root
	root = getRoot();
	scnMgr = root->createSceneManager();


	// register our scene with the RTSS
	RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);

	createScene();
	createCamera();
	createFrameListener();

}

bool OgreTutorial::keyReleased(const KeyboardEvent& evt)
{
	switch (evt.keysym.sym)
	{
	case 'w':
		m_player1Pong->SetVelocity(Ogre::Vector3(0, 0, 0));
		break;
	case 's':
		m_player1Pong->SetVelocity(Ogre::Vector3(0, 0, 0));
		break;
	default:
		break;
	}
	return true;
}

bool OgreTutorial::keyPressed(const KeyboardEvent& evt)
{
	switch (evt.keysym.sym)
	{
	case SDLK_ESCAPE:
		getRoot()->queueEndRendering();
		break;
	case 'w':
		m_player1Pong->SetVelocity(Ogre::Vector3(0,0,-m_player1Pong->GetSpeed()));
		break;
	case 's':
		m_player1Pong->SetVelocity(Ogre::Vector3(0, 0, m_player1Pong->GetSpeed()));
		break;
	default:
		break;
	}
	return true;
}


void OgreTutorial::createScene()
{
	// -- tutorial section start --

	Ogre::SceneNode* node = scnMgr->createSceneNode("Node1");
	scnMgr->getRootSceneNode()->addChild(node);

	scnMgr->setShadowTechnique(ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE);

	//! [turn lights]
	scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	//! [turn lights]

 //! [new light]
 //

	Ogre::Light* light = scnMgr->createLight("Light1");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(Ogre::Vector3(1, -1, 0));

	// Set Light Color
	light->setDiffuseColour(1.0f, 1.0f, 1.0f);
	// Set Light Reflective Color
	light->setSpecularColour(1.0f, 1.0f, 0.0f);
	// Set Light (Range, Brightness, Fade Speed, Rapid Fade Speed)
	//light1->setAttenuation(10, 0.5, 0.045, 0.0);

	//
	Entity* lightEnt = scnMgr->createEntity("LightEntity", "sphere.mesh");
	SceneNode* lightNode = node->createChildSceneNode("LightNode");
	lightNode->attachObject(lightEnt);
	lightNode->attachObject(light);
	lightNode->setScale(0.01f, 0.01f, 0.01f);

	//! [newlight]
	//The first thing we'll do is create an abstract Plane object. This is not the mesh, it is more of a blueprint.
	Plane plane(Vector3::UNIT_Y, -10);
	//Now we'll ask the MeshManager to create us a mesh using our Plane blueprint. The MeshManager is already keeping track of the resources we loaded when initializing our application. On top of this, it can create new meshes for us.
	MeshManager::getSingleton().createPlane(
		"ground", RGN_DEFAULT,
		plane,
		1500, 1500, 20, 20,
		true,
		1, 5, 5,
		Vector3::UNIT_Z);

	//Now we will create a new Entity using this mesh.
	//We want to tell our SceneManager not to cast shadows from our ground Entity. It would just be a waste. Don't get confused, this means the ground won't cast a shadow, it doesn't mean we can't cast shadows on to the ground.
	Entity* groundEntity = scnMgr->createEntity("ground");
	scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setCastShadows(false);
	//And finally we need to give our ground a material.
	groundEntity->setMaterialName("Examples/BeachStones");

	/*
	Entity* ent = scnMgr->createEntity("Sinbad.mesh");
	ent->setCastShadows(true);
	SinbadNode = scnMgr->createSceneNode("Character");
	SinbadNode->attachObject(ent);
	scnMgr->getRootSceneNode()->addChild(SinbadNode);
	SinbadNode->setPosition(Ogre::Vector3(0.0f, 4.0f, 0.0f));
	SinbadNode->setScale(3.0f, 3.0f, 3.0f);
	*/

	m_player1Pong = new PongPaddle(scnMgr->createSceneNode("Player1"),scnMgr);
	m_ball = new PongBall(scnMgr->createSceneNode("Ball"), scnMgr);
}

void OgreTutorial::createCamera()
{
	//! [camera]
	SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

	// create the camera
	Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	camNode->setPosition(0, 400, 000);
	camNode->lookAt(Ogre::Vector3(0, 0, 0), Node::TS_WORLD);

	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);

	//! [camera]
	

}

void OgreTutorial::createFrameListener()
{
	Ogre::FrameListener* P1FrameListener =  m_player1Pong;
	Ogre::FrameListener* BallFrameListener = m_ball;

	mRoot->addFrameListener(P1FrameListener);
	mRoot->addFrameListener(m_ball);
}

int main(int argc, char** argv)
{
	try
	{
		OgreTutorial app;
		app.initApp();
		app.getRoot()->startRendering();
		app.closeApp();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred during execution: " << e.what() << '\n';
		return 1;
	}

	return 0;
}

