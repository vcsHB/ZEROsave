#include "Collider.h"



Collider::Collider(Object* owner, ColliderType type, ColliderType target)
{
	_colliderType = type;
	_collisionTarget = target;
	_owner = owner;

	OnCollisionEvent = new Delegate();
	OnHitEvent = new Delegate();


	_map = Map::GetInstance();

	_objectManager = ObjectManager::GetInstance();
}

bool Collider::CheckCollision()
{
	if (_objectManager->FindObject(_owner->newPosition) == nullptr) {
		return false;
	}
	OnCollisionEvent->Invoke();

    return true;
}

void Collider::HandleHitEvent()
{
	OnHitEvent->Invoke();
}
