#pragma once
#include "GameLogic.h" 
#include <iostream>

using namespace std;

class TitleScene : public GameLogic
{
private:
    bool isRendered = false; // �÷��� ���� �߰�

public:
     bool Init() override ;

    virtual SceneState Update() override {
        cout << "Title Scene Updated" << endl;
        return { false, true, SceneTypeEnum::InGame };
    }

    virtual void Render() override;
};