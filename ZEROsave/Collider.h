#pragma once
#include "Object.h"
#include "Map.h"
#include "delegate.h"
//#include "delegate.h"

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
	ColliderType _colliderType;
	ColliderType _collisionTarget;
	Object* _owner;
	Map* _map;


public:
	delegate OnCollisionEvent;


	Collider(Object* owner, ColliderType type, ColliderType target) {
		_colliderType = type;
		_collisionTarget = target;
		_owner = owner;
		_map = Map::GetInstance();
	}


	bool CheckCollision();
};

