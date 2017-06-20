#include "Player.h"
#include "input.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "CollisionManager.h"
#include <crtdbg.h>
using namespace aie;
//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Player::Player()
{
	_ASSERT(m_ShipTexture);
	m_ShipTexture = new Texture("./textures/ship.png");
	speed = 500.0f;
	mass = 1.5f;
	RotateSpeed = 3;
	drag = 1.0f;
	// adds this object to the collisionmanager
	CollisionManager::GetInstance()->AddObject(this);
}
//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Player::~Player()
{
	delete m_ShipTexture;
}
//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call in milliseconds
//----------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
	Input* input = Input::getInstance();
	float Rotate = 0;
	dir = Vector2(0, 0);
	// lets the player move forwards, backwards
	if (input->isKeyDown(INPUT_KEY_W))
		dir = Vector2(0, 1);
	if (input->isKeyDown(INPUT_KEY_S))
		dir = Vector2(0, -1);
	// lets the player rotate left, right
	if (input->isKeyDown(INPUT_KEY_D))
		Rotate = -RotateSpeed * deltaTime;
	if (input->isKeyDown(INPUT_KEY_A))
		Rotate = RotateSpeed * deltaTime;
	// adds velocity and drag to the player so it does not just take off, also
	// so it can slow down and stop
	Vector2 forceSum = dir * speed;
	Vector2 acceleration = forceSum / mass;
	Vector2 dampening = -(vel * drag);
	vel += (acceleration + dampening) * deltaTime;
	pos = vel * deltaTime;
	// creates a matrix to hold the new data
	Matrix3 ChangePos;
	Matrix3 ChangeRotate;
	// puts the new data into the matrix
	ChangePos.setPos(pos);
	ChangeRotate.setRotateZ(Rotate);
	// updates matrix data for next update
	m_localMatrix = m_localMatrix * ChangePos;
	m_localMatrix = m_localMatrix * ChangeRotate;
	transform();
	
	// checks if it has collided with an object and if it has makes it bounce back
	// also adds more mass so it is harder to go through the object
	Entity* Coll = CollisionManager::GetInstance()->TestCollisionAABB(this);
	if (Coll != nullptr)
	{
		mass = 25.0;
		vel = -vel;
		pos = vel * deltaTime;
	}
	else
	{
		mass = 1.5f;
	}
}
//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Player::Draw(aie::Renderer2D*	m_2dRenderer)
{
	// sets the camera to the player
	m_2dRenderer->setCameraPos(m_globalMatrix.m[2][0] - 640, m_globalMatrix.m[2][1] - 360);
	m_2dRenderer->drawSpriteTransformed3x3(m_ShipTexture, m_globalMatrix);
}
