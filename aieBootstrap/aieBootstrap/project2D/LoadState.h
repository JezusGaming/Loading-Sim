#pragma once
#include "BaseState.h"
class LoadState : public BaseState
{
public:
	LoadState();
	~LoadState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float deltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:

	aie::Texture*		m_Spinner;
	aie::Font*			m_font;

	float fAlpha;
	float fTimer;
};

