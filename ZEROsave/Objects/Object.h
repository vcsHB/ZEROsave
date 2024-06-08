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
	//Agent _owner;

public:
	
	/*Movement(Agent agent) {
		_owner = agent;
	}*/

	void MoveTo(Position targetPos) {

	}

};

class Object
{
public :

	Position position;
	

};

class DamageableObject : public Object {

public:
	Health HealthCompo;


};


