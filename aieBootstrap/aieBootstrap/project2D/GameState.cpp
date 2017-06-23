#include "GameState.h"
#include "Input.h"
#include "Texture.h"
#include "Font.h"
#include "ResourceManager.h"
#include "ObjectPool.h"


using namespace aie;

GameState::GameState()
{
}


GameState::~GameState()
{
}

void GameState::OnEnter(StateMachine * pMachine)
{
	/*player = new ObjectPool(10);

	ObjectPool pool(10);

	Entity* p = pool.Allocate();

	pool.Deallocate(p);*/

	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_shipTexture = pTextureManager->LoadResource("./textures/ship.png");

	m_fidgetTexture = pTextureManager->LoadResource("./textures/FStest.png");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
}

void GameState::OnUpdate(float deltaTime, StateMachine * pMachine)
{

	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// example of audio
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
	}
}

void GameState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_fidgetTexture, 600, 600, 0, 0, sin(m_timer) * 15, 1);
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_fidgetTexture, 700, 500, 0, 0, sin(m_timer) * 10, 1);
	m_2dRenderer->setRenderColour(0, 5, 5, 1);
	m_2dRenderer->drawSprite(m_fidgetTexture, 500, 500, 0, 0, sin(m_timer) * 5, 1);

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, sin(m_timer), 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(tan(m_timer) + sin(m_timer) + 1, tan(m_timer) + 0, sin(m_timer) + 1, cos(m_timer) + 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
}

void GameState::OnExit(StateMachine * pMachine)
{
	
}
