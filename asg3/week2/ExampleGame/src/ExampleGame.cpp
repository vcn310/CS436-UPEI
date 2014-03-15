//------------------------------------------------------------------------
// ExampleGame
//
// Created:	2012/12/06
// Author:	Carel Boers
//	
// Main game class. Derives from Common::Game.
//------------------------------------------------------------------------


#include "ExampleGame.h"

#include "W_Model.h"

#include "week2/ExampleGame/DebugCube.h"
#include "week2/ExampleGame/Particle.h"
#include "week2\ExampleGame\Scene.h"
#include <ctime>
#include "week2/ExampleGame/Effect.h"

using namespace week2;


ExampleGame::ExampleGame()
{
}


ExampleGame::~ExampleGame()
{
}

static Effect* effect = nullptr;

bool ExampleGame::Init()
{
	Scene::CreateInstance();
	Camera *pCamera1 = new Camera(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f, glm::vec3(-50.0f, 0.0f, 10.0f), glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));

	Scene::Instance()->SetActiveCamera(pCamera1);

	//Particle *particle = new Particle(0, glm::vec3((rand()%20 + 10)*0.1f, (rand()%20+ 10)*0.1f, (rand()%20+ 10)*0.1f));
	//Scene::Instance()->AddTopNode(particle);

	effect = new Effect(0,glm::vec3(0.0f,0.0f,0.0f));
	Scene::Instance()->AddTopNode(effect);

	srand(static_cast<unsigned int>(time(0)));

	for (int j = 0; j<0; j++)
	{
		DebugCube *cube = new DebugCube(Scene::Instance()->GetCurrentNodeID(), glm::vec3(rand()%100, 0.0f /*rand()%100*/, rand()%100), glm::vec3((rand()%20 + 10)*0.1f, (rand()%20+ 10)*0.1f, (rand()%20+ 10)*0.1f));
		Scene::Instance()->AddTopNode(cube);
	}
	
	return true;
}


bool ExampleGame::Update(float p_fDelta)
{
	Scene::Instance()->Update(p_fDelta);

	return true;
}


void ExampleGame::Render()
{
	Scene::Instance()->Render();
}


void ExampleGame::Shutdown()
{
}