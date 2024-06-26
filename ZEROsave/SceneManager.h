#pragma once
#include "GameLogic.h"
#include "GameScene.h"
#include "TitleScene.h"

class SceneManager
{
private :
	// �ʱ� �� Ÿ���� �ʱⰪ���� ����
	SceneTypeEnum _currentSceneType = SceneTypeEnum::Title;

	class TitleScene* titleScene = nullptr;
	class GameScene* gameScene = nullptr;
	class GameLogic* _currentScene = nullptr;

public :
	

	void Initialize();

	void Start();

	void FrameSync(unsigned int _Framerate);

	~SceneManager() {
		/*delete titleScene;
		delete gameScene;*/

		// nullptr�� �����ؾߵǴ���
	}




};

