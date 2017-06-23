#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "ResourceManager.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoadState.h"
#include <crtdbg.h>


using namespace aie;
//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Application2D::Application2D() 
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Application2D::~Application2D() 
{
}

//----------------------------------------------------------------------------
// custom constructor which initalies variables, resoucemanager, statemachine	
//----------------------------------------------------------------------------
bool Application2D::startup() 
{
	
	m_2dRenderer = new Renderer2D();
	_ASSERT(m_2dRenderer);

	ResourceManager<Texture>::Create();

	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	
	m_shipTexture = pTextureManager->LoadResource("./textures/ship.png");

	/*m_shipTexture = new Texture("./textures/ship.png");*/

	/*_ASSERT(m_font);
	m_font = new Font("./font/consolas.ttf", 32);*/

	/*m_audio = new Audio("./audio/powerup.wav");*/

	
	

	// initilases statemachine
	m_pStateMachine = new StateMachine();
	_ASSERT(m_pStateMachine);

	// creates 
	m_pStateMachine->AddState(0, new SplashState());
	m_pStateMachine->AddState(1, new MenuState());
	m_pStateMachine->AddState(2, new LoadState());
	m_pStateMachine->AddState(3, new GameState());

	//
	m_pStateMachine->PushState(0);

	return true;
}

//----------------------------------------------------------------------------
// custom destructor deletes new variables, and stops memory leaks
//----------------------------------------------------------------------------
void Application2D::shutdown() 
{
	/*delete m_audio;*/
	/*delete m_font;*/
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_pStateMachine;
}

//----------------------------------------------------------------------------
// updates the game and all functions, it calls updates on the statemachine
//
// Param:
//		deltaTime: calls a timer every frame per second that holds the time
//		between now and last call in milliseconds
//----------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	//updates current statemachine
	m_pStateMachine->Update(deltaTime);

	Input* input = Input::getInstance();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();

}

//----------------------------------------------------------------------------
// draws textures for this class and sets camera
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draws current statemachine
	m_pStateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}



