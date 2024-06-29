#pragma once
#include "Map.h"
#include "Object.h"
#include "LifeTimeLimitedObject.h"
#include "ObjectManager.h"
#include "Collider.h"

class Map;
class Collider;

class Projectile : public LifeTimeLimitedObject
{
protected :
	Map* _map;
	Collider* _collider;
	ObjectManager* _objectManager;
protected:
	Position _direction; // 벡터와 같은 역할을 한다
	int _damage;
	int _moveCooltime;
public:
	bool isActive;


	void InitializeProjectile(Position position, Position direction, int damage, int _moveCooltime, float lifeTime);

	void Update() override;

	bool CheckCollision();

	void Move();

	void Destroy() override;

	~Projectile() {
		delete _collider;
	}

};

class PlayerProjectile : public Projectile 
{
public:
	PlayerProjectile() {
	}
	void Initialize() override;


};

class EnemyProjectile : public Projectile
{
public:

	void Initialize() override;

};

