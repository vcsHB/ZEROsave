#include "Collider.h"

#include "Agent.h"

Collider::Collider(Object* owner, ColliderType type, ColliderType target)
{
	_colliderType = type;
	_collisionTarget = target;
	_owner = owner;

	

	_map = Map::GetInstance();

	_objectManager = ObjectManager::GetInstance();
}

bool Collider::CheckCollision()
{
	Object* object = _objectManager->FindObject(_owner->newPosition);
	
	if (object == nullptr) {
		return false;
	}
	Agent* agent = (Agent*)object;
	OnCollisionEvent.Invoke(this);
	agent->collider->HandleHitEvent();
    return true;
}

void Collider::HandleHitEvent()
{
	OnHitEvent.Invoke(this);
}
