#include "Enemy.h"
#include "Movement.h"
#include "Stat.h"
#include "Collider.h"
void Enemy::TakeDamage(int amount)
{
	if (Status->isResist) return;
	HealthCompo->TakeDamage(amount);
}

void Enemy::Initialize()
{
	_enemyAI = new EnemyAI();
	collider = new Collider(this, ColliderType::Enemy, ColliderType::Player);

	_enemyAI->Initialize(this);
	MovementCompo = new Movement(this);
	Status = new Stat();

	objectIcon = "¡Ý";
	objectColor = COLOR::RED;
	objectBackgroundColor = COLOR::BLACK;
}

void Enemy::Update()
{
	_enemyAI->Update();
}
