#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"

class Application2D : public aie::Application {
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	Application2D();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	virtual ~Application2D();

	//----------------------------------------------------------------------------
	// custom constructor which initalies variables, resoucemanager, statemachine	
	//----------------------------------------------------------------------------
	virtual bool startup();

	//----------------------------------------------------------------------------
	// custom destructor deletes new variables, and stops memory leaks
	//----------------------------------------------------------------------------
	virtual void shutdown();

	//----------------------------------------------------------------------------
	// updates the game and all functions, it calls updates on the statemachine
	//
	// Param:
	//		deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//----------------------------------------------------------------------------
	virtual void update(float deltaTime);

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	virtual void draw();

protected:
	//----------------------------------------------------------------------------
	// pointer to aieboostrap classes
	//----------------------------------------------------------------------------
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	//----------------------------------------------------------------------------
	// pointer to statemachine
	//----------------------------------------------------------------------------
	StateMachine* m_pStateMachine;
};