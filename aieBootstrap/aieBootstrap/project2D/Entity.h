#pragma once
#include <vector>
#include "Collider.h"
#include "Matrix3.h"
#include "Texture.h"
#include "Renderer2d.h"
class Entity
{

public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	Entity();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~Entity();

	//----------------------------------------------------------------------------
	// sets the parent of an object
	//
	// Param:
	//      sParent: is what the child will follow and be apart of
	//		
	//----------------------------------------------------------------------------
	void SetParent(Entity* sParent);

	//----------------------------------------------------------------------------
	// sets the child of an object
	//
	// Param:
	//      sChild: what will be set as a child of the parent
	//		
	//----------------------------------------------------------------------------
	void SetChild(Entity* sChild);

	//----------------------------------------------------------------------------
	// it creates a update for all classes inherited from this
	//
	//----------------------------------------------------------------------------
	virtual void Update();

	//----------------------------------------------------------------------------
	// it creates a draw for all classes inherited from this
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	virtual void Draw(aie::Renderer2D*	m_2dRenderer);

	//----------------------------------------------------------------------------
	// updates the child to follow the parent if it is the parent it holds the 
	// information of the position etc that the child follows
	//----------------------------------------------------------------------------
	void transform();

	//----------------------------------------------------------------------------
	// gets the position of the object
	// 
	// return:
	//		returns the location of the object such as a position of (3,5)
	//----------------------------------------------------------------------------
	Vector2 GetPos();

	//----------------------------------------------------------------------------
	// gets the collider for example BR and TL
	// 
	// return:
	//		returns collider
	//----------------------------------------------------------------------------
	Collider& GetCollider();

	void setActive(bool bActive);
	bool getActive();

protected:
	//----------------------------------------------------------------------------
	// textures for objects
	//----------------------------------------------------------------------------
	aie::Texture*		m_ShipTexture;

	Entity* m_Parent;
	std::vector<Entity*> m_Child;

	Matrix3 m_localMatrix;
	Matrix3 m_globalMatrix;

	Collider m_Collider;

	bool m_bActive;
};	


