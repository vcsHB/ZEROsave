#include "Player.h"
#include "Movement.h"
#include "Stat.h"
#include "Collider.h"

void Player::TakeDamage(int amount)
{
	if (Status->isResist, HealthCompo->GetCurrentHP() <= 0) return;
	HealthCompo->TakeDamage(amount);
}

void Player::Initialize()
{
	MovementCompo = new Movement(this);
	Status = new Stat();
	collider = new Collider(this, ColliderType::Player, ColliderType::Object);

	objectIcon = "¢Ã";
	objectColor = COLOR::SKYBLUE;
	objectBackgroundColor = COLOR::BLACK;

	HealthCompo->OnDieEvent.Add(std::bind(&Player::HandlePlayerDie, this, std::placeholders::_1));
	collider->OnHitEvent.Add(std::bind(&Player::HandleEnemyCollision, this, std::placeholders::_1));
}

void Player::HandleEnemyCollision(Collider* hit) {
	TakeDamage(1);
}

void Player::Update()
{
}

void Player::HandlePlayerDie(bool value)
{
	OnPlayerDieEvent.Invoke(value);
}
