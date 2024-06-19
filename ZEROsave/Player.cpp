#include "Player.h"

void Player::TakeDamage(int amount)
{
	if (Status->isResist) return;
	HealthCompo->TakeDamage(amount);
}

void Player::Initialize()
{
	MovementCompo = new Movement(this);
	Status = new Stat();
	objectIcon = "¢Ã";
	objectColor = COLOR::SKYBLUE;
	objectBackgroundColor = COLOR::BLACK;
}
