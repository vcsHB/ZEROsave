#include "Player.h"
#include "Movement.h"
#include "Stat.h"
#include "Collider.h"
#include "Projectile.h"

void Player::TakeDamage(int amount)
{
	if (Status->isResist || HealthCompo->GetCurrentHP() <= 0) return;
	HealthCompo->TakeDamage(amount);
}

void Player::Initialize()
{
	MovementCompo = new Movement(this);
	Status = new Stat();
	collider = new Collider(this, ColliderType::Player, ColliderType::Object);
	_map = Map::GetInstance();

	objectIcon = "▣";
	objectColor = COLOR::SKYBLUE;
	objectBackgroundColor = COLOR::BLACK;

	HealthCompo->OnDieEvent.Add(std::bind(&Player::HandlePlayerDie, this, std::placeholders::_1));
	collider->OnHitEvent.Add(std::bind(&Player::HandleEnemyCollision, this, std::placeholders::_1));
}

void Player::HandleEnemyCollision(Collider* hit) {
	TakeDamage(1);
}

void Player::Update()
{
	_attackCooldown += 0.1f;
	MoveControl();
	AttackControl();
}

void Player::HandlePlayerDie(bool value)
{
	OnPlayerDieEvent.Invoke(value);
}

void Player::MoveControl()
{
	newPosition = position;
	// 인풋 받아와서 이동코드 작성
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		--newPosition.y;
		lastVelocity = { 0,-1 };
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		++newPosition.y;
		lastVelocity = { 0,1 };
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		newPosition.x--;
		lastVelocity = { -1,0 };
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		newPosition.x++;
		lastVelocity = { 1,0 };
	}
	// 이동 감지가 없으면 리턴
	if (position == newPosition) return;

	newPosition.ClampX(0, _map->MapWidth - 1);
	newPosition.ClampY(0, _map->MapHeight - 1);
	MapTile tile = _map->GetTile(newPosition);
	if ((int)tile.tileType != 1) {
		return;
	}

	MovementCompo->MoveTo(newPosition);

}

void Player::AttackControl()
{
	if (_attackCooldown < attackCooltime) return;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		// 공격 구현 해야디
		_attackCooldown = 0;
		PlayerProjectile* projectile = new PlayerProjectile();
		projectile->Initialize();
		projectile->InitializeProjectile(position, lastVelocity, 1, 1, 5);
		ObjectManager::GetInstance()->GenerateObject(projectile);
		/*GotoPos(0, 10);
		cout << "플레이어 공격 함";*/
	}

}
