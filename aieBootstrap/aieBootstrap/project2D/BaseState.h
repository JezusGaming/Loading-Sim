#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;

class BaseState
{
public:
	BaseState();
	~BaseState();

	virtual void OnEnter(StateMachine* pMachine) = 0;
	virtual void OnUpdate(float deltaTime, StateMachine* pMachine) = 0;
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	virtual void OnExit(StateMachine* pMachine) = 0;

private:

};

