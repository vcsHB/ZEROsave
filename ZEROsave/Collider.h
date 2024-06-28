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
	// �Ϲ����� �浹 �̺�Ʈ
	Delegate<Collider*> OnCollisionEvent;
	// �ǰݰ����� �̺�Ʈ�� ó���ϴ� �̺�Ʈ
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

