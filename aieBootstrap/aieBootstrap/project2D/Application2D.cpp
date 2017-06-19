#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "ResourceManager.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoadState.h"



using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	ResourceManager<Texture>::Create();

	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	
	m_shipTexture = pTextureManager->LoadResource("./textures/ship.png");

	/*m_shipTexture = new Texture("./textures/ship.png");*/

	m_font = new Font("./font/consolas.ttf", 32);

	/*m_audio = new Audio("./audio/powerup.wav");*/

	m_pStateMachine = new StateMachine();

	m_pStateMachine->AddState(0, new SplashState());
	m_pStateMachine->AddState(1, new MenuState());
	m_pStateMachine->AddState(2, new LoadState());
	m_pStateMachine->AddState(3, new GameState());

	m_pStateMachine->PushState(0);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	/*delete m_audio;*/
	delete m_font;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	m_pStateMachine->Update(deltaTime);

	Input* input = Input::getInstance();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();

}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pStateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}