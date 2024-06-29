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
        // ���� �ð��� ��� ����
        isDestroyed = true;
        Destroy();
    }

    return;
}
