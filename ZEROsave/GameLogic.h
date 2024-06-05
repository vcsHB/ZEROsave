#pragma once

enum class SceneTypeEnum {
	Title,
	InGame
};


class GameLogic {

public:
	SceneTypeEnum sceneType;


	/**
	 ���� ���۵ɶ� ����Ǵ� �Լ�
	*/
	virtual bool Init();

	/**
	���� �����ϸ� �� �����Ӹ��� ����Ǵ� �Լ�
	*/
	virtual void Update();
	
	/**
	Update�Լ��� ����ǰ� ���� �ܼ�â�� �� �����Ӹ��� �׷��ִ� �Լ�
	*/
	virtual void Render();

private:

};
