#include "FieldObject.h"
#include "Collider.h"
void FieldObject::Initialize() 
{
	_collider = new Collider(this, ColliderType::Object, ColliderType::Player);
	HealthCompo->OnDieEvent.Add(std::bind(&FieldObject::Destroy, this, std::placeholders::_1));
}

void FieldObject::TakeDamage(int amount)
{
	HealthCompo->TakeDamage(amount);
		
}

void FieldObject::Update()
{
}





