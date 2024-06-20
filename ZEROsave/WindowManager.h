#pragma once
#include <queue>
#include "Object.h"
#include "console.h"

struct Sequence {

	Position newPosition;
	float duration;

};
// 콘솔 자체움직임을 관리한다
class WindowManager
{
private :
	std::queue<Sequence> _sequenceQueue;
	Sequence _currentSequence;

	bool _isPlaying;
	float _currentTime;

public :
	// 시퀀싱을 멈춘다
	void Stop();
	// 시퀀스 큐를 초기화한다, 현재 진행중인것은 지우지 않는다
	void ClearQueue();
	// 현재 시퀀스를 지정한다
	void SetSequence(Sequence seq);
	// 시퀀스큐에 시퀀스를 추가한다
	void AppendQueue(Sequence seq);

	// GameScene에서 해줘야하는 Update이다
	void UpdateWindow();

	// 부가 기능 Shake
	void DOShake();
};

