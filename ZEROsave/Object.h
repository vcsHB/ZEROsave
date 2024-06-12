#pragma once

struct Position
{
public :
	int x;
	int y;

};

class Health {
private :
	int _currentHP;
public:
	
	int maxHP;

	void TakeDamage(int amount) {
		_currentHP -= amount;
	}

	void RestoreHealth(int amount) {
		_currentHP += amount;
	}

	int GetCurrentHP() { return _currentHP; }


};

class Movement 
{
private:
	class Agent* _owner;

public:
	
	Movement(Agent* agent) {
		_owner = agent;
	}

	virtual void MoveTo(Position targetPos);

};

class Object
{
public :

	Position position;
	

};

class DamageableObject : public Object {

public:
	Health* HealthCompo;

	DamageableObject() {
		HealthCompo = new Health();
	}

	virtual void TakeDamage() = 0;
};

