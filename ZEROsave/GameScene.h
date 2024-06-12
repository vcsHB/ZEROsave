#pragma once
#include "Define.h"
#include <vector>
#include "GameLogic.h"
#include "Object.h"
#include "Player.h"



class GameScene : public GameLogic
{
private :
	std::vector<Object> _objectList;

public:

	virtual bool Init() override;

	virtual SceneState Update() override;

	virtual void Render() override;


	void RenderMap();


};

