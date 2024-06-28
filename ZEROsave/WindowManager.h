#pragma once
#include <queue>
#include "Object.h"
#include "console.h"

class Object;

struct Sequence 
{
	Position newPosition;
	float duration;

};
// �ܼ� ��ü�������� �����Ѵ�
class WindowManager
{
private :
	Position _currentPosition;
	std::queue<Sequence> _sequenceQueue;
	Sequence _currentSequence;

	bool _isPlaying;
	float _currentTime;

public :
	int windowSizeX;
	int windowSizeY;

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

