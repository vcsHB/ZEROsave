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

		// 씬 변경여부가 체크되었을때
		if (state.IsExit) {
			// 타입에 따라 씬 변경
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

			//변경후 Initialize
			if (!_currentScene->Init()) {
				cout << "Init Error";
			}
		}


	}
}
