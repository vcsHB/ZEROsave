#pragma once
#include "Map.h"
#include "LifeTimeLimitedObject.h"
#include "Object.h"

class Projectile : public LifeTimeLimitedObject
{
protected :
	Map* _map;

protected:

	Position _direction; // 벡터와 같은 역할을 한다
	int _damage;
	int _moveCooltime;
public:
	bool isActive;

	Projectile(Map* map) {
		_map = map;
	}

	void Initialize(Position position, Position direction, int damage, int _moveCooltime, float lifeTime);

	virtual void Update() override;

	void CheckCollision();

	const void Move() {
		position.VectorAdd(_direction);
	}

	virtual void Destroy() override;

};

