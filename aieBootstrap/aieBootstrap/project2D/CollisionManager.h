#pragma once
#include<vector>
#include "Entity.h"

class CollisionManager
{
public:
	static CollisionManager* GetInstance();
	
	//----------------------------------------------------------------------------
	// creates collision manager
	//----------------------------------------------------------------------------
	static void Create();

	//----------------------------------------------------------------------------
	// destroys collision manager
	//----------------------------------------------------------------------------
	static void Destroy();

	//----------------------------------------------------------------------------
	// adds an object to the collision manager
	//
	// param:
	//		pObject: is the object the collision manager is being used in
	//----------------------------------------------------------------------------
	void AddObject(Entity* pObject);

	//----------------------------------------------------------------------------
	// removes an object to the collision manager
	//
	// param:
	//		pObject: is the object the collision manager is being used in
	//----------------------------------------------------------------------------
	void RemoveObject(Entity* pObject);

	//----------------------------------------------------------------------------
	// checks axis aligned bounding box collision for two objects
	//
	// param:
	//		pObject: is the object the collision manager is being used in
	//
	// return:
	//		returns nullptr is it does not collide if it does then it returns
	//		the collisionlist
	//----------------------------------------------------------------------------
	Entity* TestCollisionAABB(Entity* pObject);
private:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	CollisionManager();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~CollisionManager();

	static CollisionManager* m_instance;

	std::vector<Entity*> m_Collisionlist;
};

