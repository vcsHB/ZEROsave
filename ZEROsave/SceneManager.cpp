#pragma comment(lib, "winmm.lib")
#include "SceneManager.h"

void SceneManager::Initialize()
{
	if (titleScene == nullptr)
		titleScene = new TitleScene();
	if (gameScene == nullptr)
		gameScene = new GameScene();


}

void SceneManager::Start() {
	_currentScene = titleScene;
	while (true)
	{
		SceneState state;

		state = _currentScene->Update();
		
		_currentScene->Render();

		// �� ���濩�ΰ� üũ�Ǿ�����
		if (state.IsExit) {
			// Ÿ�Կ� ���� �� ����
			switch (state.NextScene)
			{
			case SceneTypeEnum::Title:
				_currentScene = titleScene;
				break;
			case SceneTypeEnum::InGame:
				_currentScene = gameScene;
				break;
			default:
				cout << "not Exist Scene";
				return;
			}

			//������ Initialize
			if (!_currentScene->Init()) {
				cout << "Init Error";
			}
		}
		FrameSync(60);

	}
}

void SceneManager::FrameSync(unsigned int _Framerate)
{
	clock_t oldtime, curtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _Framerate)
		{
			oldtime = curtime;
			break;
		}
	}
}
