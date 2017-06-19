#include "LoadState.h"
#include "Input.h"
#include "Texture.h"
#include "Font.h"
#include "ResourceManager.h"
#include "StateMachine.h"

LoadState::LoadState()
{
	m_font = new Font("./font/consolas.ttf", 32);
}

LoadState::~LoadState()
{
	delete m_font;
}

void LoadState::OnEnter(StateMachine * pMachine)
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_Spinner = pTextureManager->LoadResource("./textures/FStest.png");

	fTimer = 0.0f;
}

void LoadState::OnUpdate(float deltaTime, StateMachine * pMachine)
{
	fTimer += deltaTime;

	if (fTimer >= 10.0f)
	{
		pMachine->PushState(3);
	}

}

void LoadState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_Spinner, 75, 75, 0, 0, fTimer * 11, 1);
	m_2dRenderer->setRenderColour(255, 255, 255, 1);	
	m_2dRenderer->drawText(m_font, "Loading... :)", 150, 125 - 64);
}

void LoadState::OnExit(StateMachine * pMachine)
{
	fTimer = 0.0f;
}
