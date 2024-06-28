#include "Projectile.h"

void Projectile::Initialize
(Position position, Position direction, int damage, int moveCooltime, float lifeTime)
{
	this->position = position;
	_direction = direction;
	_damage = damage;
	_moveCooltime = moveCooltime;
	_lifeTime = lifeTime;
	isActive = true;
}

void Projectile::Update()
{
	if (!isActive) return;

	LifeTimeLimitedObject::Update();

	

}
