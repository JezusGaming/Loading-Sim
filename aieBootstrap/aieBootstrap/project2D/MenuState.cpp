#include "MenuState.h"
#include "Input.h"
#include "Texture.h"
#include "Font.h"
#include "ResourceManager.h"
#include "StateMachine.h"

MenuState::MenuState()
{
	m_font = new Font("./font/consolas.ttf", 32);
}


MenuState::~MenuState()
{
	delete m_font;
}

void MenuState::OnEnter(StateMachine * pMachine)
{
	fAlpha = 0.0f;
	fTimer = 0.0f;
}

void MenuState::OnUpdate(float deltaTime, StateMachine * pMachine)
{
	// input example
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		pMachine->PushState(2);
	}

	fTimer += deltaTime;

	if (fTimer <= 3.0f)
	{
		fAlpha += deltaTime;
	}

}

void MenuState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(255, 255, 255, fAlpha);
	m_2dRenderer->drawText(m_font, "Press Enter To Start", 460, 420 - 64);
}

void MenuState::OnExit(StateMachine * pMachine)
{
	fAlpha = 0.0f;
	fTimer = 0.0f;
}
