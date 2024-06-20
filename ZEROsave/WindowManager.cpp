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
	// 마저 구현해야됨
}

void WindowManager::DOShake()
{
	// Append를 짧은 지속시간으로 겁나 박아서 진동구현
}
