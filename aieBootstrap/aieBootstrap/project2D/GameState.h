#pragma once
#include "BaseState.h"
#include "Player.h"
class GameState : public BaseState
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float deltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:

	aie::Texture*		m_shipTexture;
	aie::Texture*		m_fidgetTexture;

	Player* player;

	float m_cameraX, m_cameraY;
	float m_timer;
	float fAlpha;
};

