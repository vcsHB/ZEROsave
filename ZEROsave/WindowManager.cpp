#include "WindowManager.h"

void WindowManager::Stop()
{
	_isPlaying = false;
	ClearQueue();
}

void WindowManager::ClearQueue()
{
	while (!_sequenceQueue.empty())
	{
		_sequenceQueue.pop();
	}
}

void WindowManager::SetSequence(Sequence seq)
{
	_isPlaying = true;
	_currentSequence = seq;
	ClearQueue();
	_sequenceQueue.push(seq);
}

void WindowManager::AppendQueue(Sequence seq)
{
	_isPlaying = true;
	_sequenceQueue.push(seq);
}

void WindowManager::UpdateWindow()
{
	if (!_isPlaying) return;
	// ���� �����ؾߵ�
}

void WindowManager::DOShake()
{
	// Append�� ª�� ���ӽð����� �̳� �ھƼ� ��������
}
