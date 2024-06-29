#include "LifeTimeLimitedObject.h"

const void LifeTimeLimitedObject::Initialize(float lifeTime)
{
    _lifeTime = lifeTime;
    isDestroyed = false;
    return;
}

void LifeTimeLimitedObject::Update()
{
    _currentTime += 0.1f;

    if (_currentTime >= _lifeTime) {
        // 생존 시간이 모두 지남
        isDestroyed = true;
        Destroy();
    }

    return;
}
