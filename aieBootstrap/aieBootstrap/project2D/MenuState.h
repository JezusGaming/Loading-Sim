#pragma once
#include "BaseState.h"
class MenuState : public BaseState
{
public:
	MenuState();
	~MenuState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float deltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:

	aie::Font*			m_font;

	float fAlpha;
	float fTimer;
};

