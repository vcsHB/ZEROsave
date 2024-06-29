#pragma once
#include "Map.h"
#include "Object.h"
#include "LifeTimeLimitedObject.h"
#include "ObjectManager.h"
#include "Collider.h"

class Collider;

class Projectile : public LifeTimeLimitedObject
{
protected :
	Map* _map;
	Collider* _collider;
protected:
	Position _direction; // 벡터와 같은 역할을 한다
	int _damage;
	int _moveCooltime;
public:
	bool isActive;

	Projectile() {
		_collider = new Collider()
	}

	void Initialize(Position position, Position direction, int damage, int _moveCooltime, float lifeTime);

	virtual void Update() override;

	void CheckCollision();

	const void Move() {
		position.VectorAdd(_direction);
	}

	virtual void Destroy() override;

};

class PlayerProjectile : public Projectile 
{
	

};

class EnemyProjectile : public Projectile
{


};

