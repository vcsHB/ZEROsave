#pragma once

enum class SceneTypeEnum {
	Title,
	InGame
};


class GameLogic {

public:
	SceneTypeEnum sceneType;


	/**
	 씬이 시작될때 실행되는 함수
	*/
	virtual bool Init();

	/**
	씬이 동작하며 매 프레임마다 실행되는 함수
	*/
	virtual void Update();
	
	/**
	Update함수가 실행되고 나서 콘솔창에 매 프레임마다 그려주는 함수
	*/
	virtual void Render();

private:

};
