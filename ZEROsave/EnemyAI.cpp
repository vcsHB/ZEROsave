#include "EnemyAI.h"

void EnemyAI::Initialize(Agent* owner) 
{
	_owner = owner;
	_map = Map::GetInstance();
	_collider = _owner->collider;
	_collider->OnCollisionEvent.Add(std::bind(&EnemyAI::MoveTurn, this, std::placeholders::_1));
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
	MapTile tile = _map->GetTile(_owner->newPosition);
	if ((int)tile.tileType != 1) {
		return;
	}
}

void EnemyAI::MoveTurn(Collider* hit)
{
	if (hit->GetColliderType() == ColliderType::Player) {
		hit->HandleHitEvent();
	}
}

void EnemyAI::Update()
{
	Move();
}
