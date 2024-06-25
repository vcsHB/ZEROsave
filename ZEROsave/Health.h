#pragma once
class Health {
private:
	int _currentHP;
public:

	int maxHP;

	void Initialize(int amount);

	void TakeDamage(int amount);

	void RestoreHealth(int amount);

	int GetCurrentHP() { return _currentHP; }


};


