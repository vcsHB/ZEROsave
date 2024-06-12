#pragma once
#include "GameLogic.h" 
//#include <iostream>
//using namespace std;

class TitleScene : public GameLogic
{
private:
    bool isRendered = false; // 플래그 변수 추가

public:
     bool Init() override ;

    virtual SceneState Update() override;

    virtual void Render() override;
};