#pragma once
#include "Object.h"
#include "Map.h"
#include "ObjectManager.h"
#include "delegate.h"

class Object;
class Map;
class ObjectManager;
class Deleagate;

enum class ColliderType {
	Wall,
	Object,
	Player,
	Enemy
};



class Collider
{
private :
	ColliderType _colliderType = ColliderType::Object;
	ColliderType _collisionTarget = ColliderType::Object;
	Object* _owner = nullptr;
	Map* _map = nullptr;
	ObjectManager* _objectManager = nullptr;


public:
	// 일반적인 충돌 이벤트
	Delegate<Collider*> OnCollisionEvent;
	// 피격과같은 이벤트를 처리하는 이벤트
	Delegate<Collider*> OnHitEvent;

	Collider() {

	}

	Collider(Object* owner, ColliderType type, ColliderType target);

	ColliderType GetColliderType() {
		return _colliderType;
	}

	Object* GetOwner() {
		return _owner;
	}

	bool CheckCollision();

	void HandleHitEvent();
};

