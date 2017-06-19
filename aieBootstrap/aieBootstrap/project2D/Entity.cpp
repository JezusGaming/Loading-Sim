#include "Entity.h"

using namespace aie;

Entity::Entity()
{
	// sets the width of the collision box and that this has no parent
	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);
	m_Parent = nullptr;

	m_bActive = false;
}

Entity::~Entity()
{
}

void Entity::setActive(bool bActive)
{
	m_bActive = bActive;
}

bool Entity::getActive()
{
	return m_bActive;
}

//----------------------------------------------------------------------------
// sets the parent of an object
//
// Param:
//      sParent: is what the child will follow and be apart of
//		
//----------------------------------------------------------------------------
void Entity::SetParent(Entity* sParent)
{
	m_Parent = sParent;
}
//----------------------------------------------------------------------------
// sets the child of an object
//
// Param:
//      sChild: what will be set as a child of the parent
//		
//----------------------------------------------------------------------------
void Entity::SetChild(Entity* sChild)
{
	m_Child.push_back(sChild);
}
//----------------------------------------------------------------------------
// it creates a update for all classes inherited from this
//
//----------------------------------------------------------------------------
void Entity::Update()
{
}
//----------------------------------------------------------------------------
// it creates a draw for all classes inherited from this
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Entity::Draw(aie::Renderer2D*	m_2dRenderer)
{
}
//----------------------------------------------------------------------------
// updates the child to follow the parent if it is the parent it holds the 
// information of the position etc that the child follows
//----------------------------------------------------------------------------
void Entity::transform()
{
	if (m_Parent != nullptr)
		m_globalMatrix = m_Parent->m_globalMatrix * m_localMatrix;
	else
		m_globalMatrix = m_localMatrix;
	for (auto child : m_Child)
		child->transform();
}
//----------------------------------------------------------------------------
// gets the position of the object
// 
// return:
//		returns the location of the object such as a position of (3,5)
//----------------------------------------------------------------------------
Vector2 Entity::GetPos()
{
	Vector2 Pos;
	Pos.x = m_globalMatrix[2][0];
	Pos.y = m_globalMatrix[2][1];
	return Pos;
}
//----------------------------------------------------------------------------
// gets the collider for example BR and TL
// 
// return:
//		returns collider
//----------------------------------------------------------------------------
Collider & Entity::GetCollider()
{
	return m_Collider;
}
