#include "Projectile.h"



void Projectile::InitializeProjectile
(Position position, Position direction, int damage, int moveCooltime, float lifeTime)
{
	_map = Map::GetInstance();
	_objectManager = ObjectManager::GetInstance();
	this->position = position;
	newPosition = position;
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

	Move();

}

bool Projectile::CheckCollision()
{
	
	MapTile tile = _map->GetTile(newPosition);
	GotoPos(0, 10);
	cout << newPosition.x << ", " << newPosition.y;
	if ((int)tile.tileType != 1 ) {
		//_collider->OnCollisionEvent.Invoke(_collider);

		return true;
	}
	return false;
}

void Projectile::Move()
{
	newPosition += _direction;
	newPosition.ClampX(0, _map->MapWidth - 1);
	newPosition.ClampY(0, _map->MapHeight - 1);
	if (!CheckCollision())
	{
		position = newPosition;
		return;
	}
	Destroy();

}

void Projectile::Destroy()
{
	/*GotoPos(0, 11);
	cout << "삭제 시작";*/
	_objectManager->DeleteObject(this);
	/*GotoPos(0, 11);
	cout << "삭제 완료";*/
	delete this;
}
// Player Projectile

void PlayerProjectile::Initialize()
{
	_collider = new Collider(this, ColliderType::Object, ColliderType::Enemy);
	objectIcon = "◈";
	objectColor = COLOR::SKYBLUE;
	objectBackgroundColor = COLOR::BLACK;

}


// Enemy Projectile
void EnemyProjectile::Initialize()
{
	_collider = new Collider(this, ColliderType::Object, ColliderType::Player);
}

