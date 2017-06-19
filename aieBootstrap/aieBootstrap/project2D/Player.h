#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	Player();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~Player();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call in milliseconds
	//----------------------------------------------------------------------------
	void Update(float deltaTime);

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	void Draw(aie::Renderer2D*	m_2dRenderer);

private:
	/*Texture* m_ship;*/
	Vector2 pos;
	Vector2 dir;
	Vector2 vel;
	float mass;
	float drag;
	float RotateSpeed;
	float speed;
};

