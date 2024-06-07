#pragma once
#include "GameLogic.h" 

class GameScene : public GameLogic
{
public:
	virtual bool Init() override {
		cout << "GameScene Init";
		return true;
	}

	virtual SceneState Update() override {
		cout << "Game Scene Updated" << endl;
		return { false, true, SceneTypeEnum::Title };
	}


	virtual void Render() override {

	}


};

