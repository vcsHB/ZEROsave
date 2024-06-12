#pragma once
#include "SceneDefine.h"



class GameLogic {

public:
	SceneTypeEnum sceneType;


	/**
	 씬이 시작될때 실행되는 함수
	*/
	virtual bool Init() = 0;

	/**
	씬이 동작하며 매 프레임마다 실행되는 함수
	반환이 false가 되면 씬을 나가는 것으로 간주
	*/
	virtual SceneState Update() = 0;
	
	/**
	Update함수가 실행되고 나서 콘솔창에 매 프레임마다 그려주는 함수
	*/
	virtual void Render() = 0;

private:

};
