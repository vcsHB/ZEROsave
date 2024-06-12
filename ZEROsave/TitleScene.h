#pragma once
#include "Define.h"
#include "GameLogic.h" 

class TitleScene : public GameLogic
{
public:
	virtual bool Init() override {
		cout << "TitleScene Init";
		return true;
	}

	virtual SceneState Update() override {

		cout << "Title Scene Updated" << endl;
		return { false, true, SceneTypeEnum::InGame };
	}

	virtual void Render() override {

	}


};

