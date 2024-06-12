#pragma once
#include "GameLogic.h"
#include "GameScene.h"
#include "TitleScene.h"

class SceneManager
{
private :
	// 초기 씬 타입을 초기값으로 지정
	SceneTypeEnum _currentSceneType = SceneTypeEnum::Title;

	class TitleScene* titleScene = nullptr;
	class GameScene* gameScene = nullptr;
	class GameLogic* _currentScene = nullptr;

public :
	

	void Initialize();

	void Start();




	~SceneManager() {
		delete titleScene;
		delete gameScene;

		// nullptr로 지정해야되던가
	}




};

