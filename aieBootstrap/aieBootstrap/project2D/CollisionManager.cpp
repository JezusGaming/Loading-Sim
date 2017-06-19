#include "CollisionManager.h"
#include <iostream>
using namespace std;

CollisionManager* CollisionManager::m_instance = nullptr;

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
CollisionManager::CollisionManager()
{
}
//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::GetInstance()
{
	return m_instance;
}
//----------------------------------------------------------------------------
// creates collision manager
//----------------------------------------------------------------------------
void CollisionManager::Create()
{
	if (!m_instance)
		m_instance = new CollisionManager();
}
//----------------------------------------------------------------------------
// destroys collision manager
//----------------------------------------------------------------------------
void CollisionManager::Destroy()
{
	delete m_instance;
}
//----------------------------------------------------------------------------
// adds an object to the collision manager
//
// param:
//		pObject: is the object the collision manager is being used in
//----------------------------------------------------------------------------
void CollisionManager::AddObject(Entity * pObject)
{
	m_Collisionlist.push_back(pObject);
}
//----------------------------------------------------------------------------
// removes an object to the collision manager
//
// param:
//		pObject: is the object the collision manager is being used in
//----------------------------------------------------------------------------
void CollisionManager::RemoveObject(Entity * pObject)
{
	auto iter = find(m_Collisionlist.begin(), m_Collisionlist.end(), pObject);
	if (iter != m_Collisionlist.end())
		m_Collisionlist.erase(iter);
}
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
Entity* CollisionManager::TestCollisionAABB(Entity* pObject)
{
	// goes through all objects in the collisionlist and checks if they collide
	for (unsigned int i = 0; i < m_Collisionlist.size(); ++i)
	{
		if (pObject == m_Collisionlist[i])
			continue;

		Collider collider1 = pObject->GetCollider();
		collider1.m_TL = collider1.m_TL + pObject->GetPos();
		collider1.m_BR = collider1.m_BR + pObject->GetPos();

		Collider collider2 = m_Collisionlist[i]->GetCollider();
		collider2.m_TL = collider2.m_TL + m_Collisionlist[i]->GetPos();
		collider2.m_BR = collider2.m_BR + m_Collisionlist[i]->GetPos();

		if (collider1.m_BR.x > collider2.m_TL.x &&
			collider1.m_BR.y > collider2.m_TL.y &&
			collider1.m_TL.x < collider2.m_BR.x &&
			collider1.m_TL.y < collider2.m_BR.y)
		{
			return m_Collisionlist[i];
		}
	}
	return nullptr;
}
