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
	_owner->newPosition = _owner->position;

	CheckCollision();
	MapTile tile = _map->GetTile(_owner->newPosition);
	if ((int)tile.tileType != 1) {
		MoveTurnForce();
		return;
	}
	_owner->position = _owner->newPosition;
	
}

void EnemyAI::MoveTurn(Collider* hit)
{
	if (hit->GetColliderType() == ColliderType::Player) {
		hit->HandleHitEvent();
	}
}

void EnemyAI::MoveTurnForce()
{
	Position direcion = _owner->lastVelocity;

	if (direcion == Position{ 1, 0 }) {
		_owner->lastVelocity = { 0,1 };
	}else if (direcion == Position{ -1, 0 }) {
		_owner->lastVelocity = { 0,-1 };
	}else if (direcion == Position{ 0, 1 }) {
		_owner->lastVelocity = { -1,0 };
	}else if(direcion == Position{ 0, -1 }) {
		_owner->lastVelocity = { 1,0 };
	}
	
}

void EnemyAI::Update()
{
	_currentMovecooldown += 0.1f;
	if (_currentMovecooldown >= _moveCooltime) {
		Move();
		_currentMovecooldown = 0;
	}
}
