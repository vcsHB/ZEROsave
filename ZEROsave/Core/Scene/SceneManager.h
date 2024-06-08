#pragma once
#include "GameLogic.h"
#include "TitleScene.h"
#include "GameScene.h"

class SceneManager
{
private :
	// 초기 씬 타입을 초기값으로 지정
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




	~SceneManager() {
		delete titleScene;
		delete gameScene;

		// nullptr로 지정해야되던가
	}




};

