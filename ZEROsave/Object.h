#pragma once

typedef struct Position
{
	int x;
	int y;

	//Position(int _x, int _y) { x = _x, y = _y; }
};

class Health {
private :
	int _currentHP;
public:
	
	int maxHP;

	void TakeDamage(int amount);

	void RestoreHealth(int amount);

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

	virtual void TakeDamage(int amount) = 0;
};


