#pragma once
#include <queue>
#include "Object.h"
#include "console.h"

struct Sequence {

	Position newPosition;
	float duration;

};
// �ܼ� ��ü�������� �����Ѵ�
class WindowManager
{
private :
	std::queue<Sequence> _sequenceQueue;
	Sequence _currentSequence;

	bool _isPlaying;
	float _currentTime;

public :
	// �������� �����
	void Stop();
	// ������ ť�� �ʱ�ȭ�Ѵ�, ���� �������ΰ��� ������ �ʴ´�
	void ClearQueue();
	// ���� �������� �����Ѵ�
	void SetSequence(Sequence seq);
	// ������ť�� �������� �߰��Ѵ�
	void AppendQueue(Sequence seq);

	// GameScene���� ������ϴ� Update�̴�
	void UpdateWindow();

	// �ΰ� ��� Shake
	void DOShake();
};

