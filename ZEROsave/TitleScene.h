#pragma once
#include "GameLogic.h"
#include <Windows.h>
#include <iostream>
#include <fcntl.h>
#include <corecrt_io.h>

enum class MENU {
    START, INFO, QUIT
};

enum class KEY {
    UP, DOWN, SPACE, FALE
};

class TitleScene : public GameLogic
{
private:
    bool isRendered = false;
    bool _isExit = false;
public:
    bool Init() override;
    SceneState Update() override;
    void Render() override;
    void Exit() override;

    MENU MenuRender();
    KEY KeyController();
    bool Title();
    void InfoRender();
    
};