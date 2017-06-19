#include "SplashState.h"
#include "Font.h"
#include "StateMachine.h"

SplashState::SplashState()
{
	m_font = new Font("./font/consolas.ttf", 32);
}

SplashState::~SplashState()
{
	delete m_font;
}

void SplashState::OnEnter(StateMachine * pMachine)
{
	fAlpha = 0.0f;
	fTimer = 0.0f;
}

void SplashState::OnUpdate(float deltaTime, StateMachine* pMachine)
{
	
	fTimer += deltaTime;

	if (fTimer <= 3.0f)
	{
		fAlpha += deltaTime;
	}

	if (fAlpha >= 1.0f)
	{
		fAlpha = 1.0f;
	}

	if (fTimer >= 3.0f)
	{
		fAlpha -= deltaTime;
	}

	if (fTimer >= 5.0f)
	{
		pMachine->PushState(1);
	}
}

void SplashState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(255, 255, 255, fAlpha);
	m_2dRenderer->drawText(m_font, "Splash Screen", 525, 420 - 64);
}

void SplashState::OnExit(StateMachine * pMachine)
{
	fAlpha = 0.0f;
	fTimer = 0.0f;
}
