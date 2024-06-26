#pragma once
#include "Object.h"
class LifeTimeLimitedObject : public Object
{
protected :
	float _currentTime;
	float _lifeTime;
public :
	bool isDestroyed;

	const void Initialize(float lifeTime);

	void Update() override;

	void virtual Destroy() = 0;


};

