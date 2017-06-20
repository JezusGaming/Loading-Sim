#pragma once
#include "DynamicArray.h"
#include "Stack.h"
#include "BaseState.h"
#include "Renderer2D.h"

using namespace aie;
class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void PopState();
	void AddState(int nStateIndex, BaseState* pState);

private:
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_CurrentStack;
};

