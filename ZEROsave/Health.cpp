#include "Health.h"

void Health::Initialize(int amount)
{
	maxHP = amount;
	_currentHP = amount;
}

void Health::TakeDamage(int amount) {
	_currentHP -= amount;
	CheckDie();
}

void Health::RestoreHealth(int amount) {
	_currentHP += amount;
	CheckDie();
}

void Health::CheckDie()
{
	if (_currentHP <= 0) {
		OnDieEvent.Invoke(true);
	}
}
