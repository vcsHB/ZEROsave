#include "Player.h"

void Player::TakeDamage(int amount)
{
	if (Status->isResist) return;
	HealthCompo->TakeDamage(amount);
}
