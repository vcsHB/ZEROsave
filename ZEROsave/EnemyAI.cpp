#include "EnemyAI.h"

void EnemyAI::Initialize(Agent* owner) 
{
	_owner = owner;
	_collider = _owner->collider;
	cout << "델리게이드 출발";
	_collider->OnCollisionEvent.Add(this, &EnemyAI::MoveTurn);
	cout << "델리게이드 ";
}

void EnemyAI::CheckCollision()
{
	_owner->newPosition = _owner->position + _owner->lastVelocity;
	if (_collider->CheckCollision()){
		_owner->newPosition = _owner->position;
	}
}

void EnemyAI::Move()
{
	CheckCollision();
	_owner->position = _owner->newPosition;
}

void EnemyAI::MoveTurn(Collider* hit)
{
	if (hit->GetColliderType() == ColliderType::Player) {
		hit->HandleHitEvent();
	}
}






