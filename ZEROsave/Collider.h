#pragma once
#include "Map.h"
#include "Object.h"
enum class ColliderType {
	Wall,
	Object,
	Player,
	Enemy
};

class Collider
{
private :
	ColliderType _colliderType;
	ColliderType _collisionTarget;
	Object* _owner;

public:
	Collider(Object* owner, ColliderType type, ColliderType target) {
		_colliderType = type;
		_collisionTarget = target;
		_owner = owner;
	}

	bool CheckCollision();
};

