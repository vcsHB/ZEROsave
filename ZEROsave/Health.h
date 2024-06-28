#pragma once
#include "delegate.h"

class Health {
private:
	int _currentHP;
public:
	class Delegate<bool> OnDieEvent;

	int maxHP;

	void Initialize(int amount);

	void TakeDamage(int amount);

	void RestoreHealth(int amount);

	void CheckDie();

	int GetCurrentHP() { return _currentHP; }


};


