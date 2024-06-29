#include "Object.h"

void Health::Initialize(int amount)
{
	maxHP = amount;
	_currentHP = amount;
}

void Health::TakeDamage(int amount){
	_currentHP -= amount;
}

void Health::RestoreHealth(int amount) {
	_currentHP += amount;
}
