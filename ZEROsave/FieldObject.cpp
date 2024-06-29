#include "FieldObject.h"

void FieldObject::Initialize() 
{
	_collider = new Collider(this, ColliderType::Object, ColliderType::Player);

	_collider->OnCollisionEvent.Add(this, FieldObject::Destroy);
}

void FieldObject::Destroy()
{
}

