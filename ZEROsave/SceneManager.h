#pragma once
#include "GameLogic.h"
#include "TitleScene.h"
#include "GameScene.h"

class SceneManager
{
private :
	// �ʱ� �� Ÿ���� �ʱⰪ���� ����
	SceneTypeEnum _currentSceneType = SceneTypeEnum::Title;

	TitleScene *titleScene;
	GameScene *gameScene;
	GameLogic *_currentScene;

public :
	

	void Initialize() {
		if(titleScene == nullptr)
			titleScene = new TitleScene();
		if (gameScene == nullptr)
			gameScene = new GameScene();
	}

	void Start() {
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

			
		}
	}




	~SceneManager() {
		delete titleScene;
		delete gameScene;

		// nullptr�� �����ؾߵǴ���
	}




};

