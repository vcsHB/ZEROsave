#include "FieldObject.h"
#include "Collider.h"
void FieldObject::Initialize() 
{
	_collider = new Collider(this, ColliderType::Object, ColliderType::Player);
	HealthCompo->OnDieEvent.Add(Destroy);

}

void FieldObject::TakeDamage(int amount)
{
	HealthCompo->TakeDamage(amount);
		
}




