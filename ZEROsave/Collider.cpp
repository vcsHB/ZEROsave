#include "Collider.h"

Collider::Collider(Object* owner, ColliderType type, ColliderType target)
{
	_colliderType = type;
	_collisionTarget = target;
	_owner = owner;
	_map = Map::GetInstance();
}

bool Collider::CheckCollision()
{
    OnCollisionEvent(this);

    return false;
}
