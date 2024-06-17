#include "Object.h"

void Health::TakeDamage(int amount){
	_currentHP -= amount;
}

void Health::RestoreHealth(int amount) {
	_currentHP += amount;
}
