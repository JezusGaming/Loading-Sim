#pragma once
#include "BaseState.h"
class SplashState : public BaseState
{
public:
	SplashState();
	~SplashState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float deltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

	

private:

	aie::Font*			m_font;

	float fTimer;
	float fAlpha;
};

