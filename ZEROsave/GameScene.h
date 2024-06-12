#pragma once
#include "GameLogic.h"
#include "Define.h"

class GameScene : public GameLogic
{
public:
	virtual bool Init() override;


	virtual SceneState Update() override;


	virtual void Render() override;


};

