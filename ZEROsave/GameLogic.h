#pragma once
#include "SceneDefine.h"



class GameLogic {

public:
	SceneTypeEnum sceneType;


	/**
	 ���� ���۵ɶ� ����Ǵ� �Լ�
	*/
	virtual bool Init() = 0;

	/**
	���� �����ϸ� �� �����Ӹ��� ����Ǵ� �Լ�
	��ȯ�� false�� �Ǹ� ���� ������ ������ ����
	*/
	virtual SceneState Update() = 0;
	
	/**
	Update�Լ��� ����ǰ� ���� �ܼ�â�� �� �����Ӹ��� �׷��ִ� �Լ�
	*/
	virtual void Render() = 0;

private:

};
