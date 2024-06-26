#pragma once
#include "Object.h"
#include "Map.h"
#include "delegate.h"

class Object;
class Map;

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


public:
	Delegate<Collider*> OnCollisionEvent;

	Collider() {

	}

	Collider(Object* owner, ColliderType type, ColliderType target);


	bool CheckCollision();
};

