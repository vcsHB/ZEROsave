#include "TitleScene.h"
#include "console.h"
#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

bool TitleScene::Init() {
    return true;
}

SceneState TitleScene::Update() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    std::cout << "Title Scene Updated" << std::endl;
    return { false, false, SceneTypeEnum::InGame };
}

void TitleScene::Render() {
    GotoPos(0, 0);
    int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << R"(
                 ________  ________  _______    ______    ______    ______   __     __  ________ 
                |        \|        \|       \  /      \  /      \  /      \ |  \   |  \|        \
                \$$$$$$$$| $$$$$$$$| $$$$$$$\|  $$$$$$\|  $$$$$$\|  $$$$$$\| $$   | $$| $$$$$$$$
                   /  $$ | $$__    | $$__| $$| $$  | $$| $$___\$$| $$__| $$| $$   | $$| $$__    
                  /  $$  | $$  \   | $$    $$| $$  | $$ \$$    \ | $$    $$ \$$\ /  $$| $$  \   
                 /  $$   | $$$$$   | $$$$$$$\| $$  | $$ _\$$$$$$\| $$$$$$$$  \$$\  $$ | $$$$$   
                /  $$___ | $$_____ | $$  | $$| $$__/ $$|  \__| $$| $$  | $$   \$$ $$  | $$_____ 
               |  $$    \| $$     \| $$  | $$ \$$    $$ \$$    $$| $$  | $$    \$$$   | $$     \
                \$$$$$$$$ \$$$$$$$$ \$$   \$$  \$$$$$$   \$$$$$$  \$$   \$$     \$     \$$$$$$$$|
    )" << std::endl;
    _setmode(_fileno(stdout), beforemode);
    MenuRender();
}

bool TitleScene::Title() {
    while (true) {
        system("cls");
        Render();
        std::cout << "Rendering Menu" << std::endl;  // 디버깅 메시지 추가
        MenuRender();
        std::cout << "Menu Rendered" << std::endl;  // 디버깅 메시지 추가

        // 잠시 대기하여 출력 확인
        Sleep(3000);

        MENU eMenu = MenuRender();
        std::cout << "Menu Selected" << std::endl;  // 디버깅 메시지 추가
        switch (eMenu) {
        case MENU::START:
            std::cout << "칙칙폭폭" << std::endl;
            return true;
        case MENU::INFO:
            InfoRender();
            break;
        case MENU::QUIT:
            return false;
        }
    }
}

void TitleScene::InfoRender() {
    system("cls");
    std::cout << "[조작법 ]" << std::endl;
    Sleep(100);
    while (true) {
        if (KeyController() == KEY::SPACE)
            break;
    }
}

MENU TitleScene::MenuRender() {
    COORD Resolution = GetConsoleResolution();
    int x = Resolution.X / 3;
    int y = static_cast<int>(Resolution.Y / 2.5);
    int originy = y;

    // 메뉴 렌더링 전 초기화
    std::cout << "MenuRender: x = " << x << ", y = " << y << std::endl;  // 디버깅 메시지 추가

    if (!GotoPos(x, y)) {
        std::cerr << "GotoPos failed at (" << x << ", " << y << ")" << std::endl;
    }
    std::cout << "게임 시작" << std::endl;

    if (!GotoPos(x, y + 1)) {
        std::cerr << "GotoPos failed at (" << x << ", " << y + 1 << ")" << std::endl;
    }
    std::cout << "게임 정보" << std::endl;

    if (!GotoPos(x, y + 2)) {
        std::cerr << "GotoPos failed at (" << x << ", " << y + 2 << ")" << std::endl;
    }
    std::cout << "게임 종료" << std::endl;

    if (!GotoPos(x - 2, y)) {
        std::cerr << "GotoPos failed at (" << x - 2 << ", " << y << ")" << std::endl;
    }
    std::cout << ">";

    while (true) {
        KEY eKey = KeyController();
        //std::cout << "Key Pressed: " << static_cast<int>(eKey) << std::endl;
        switch (eKey) {
        case KEY::UP:
            if (originy < y) {
                if (!GotoPos(x - 2, y)) {
                    std::cerr << "GotoPos failed at (" << x - 2 << ", " << y << ")" << std::endl;
                }
                std::cout << " ";
                if (!GotoPos(x - 2, --y)) {
                    std::cerr << "GotoPos failed at (" << x - 2 << ", " << y << ")" << std::endl;
                }
                std::cout << ">";
                Sleep(100);
            }
            break;
        case KEY::DOWN:
            if (originy + 2 > y) {
                if (!GotoPos(x - 2, y)) {
                    std::cerr << "GotoPos failed at (" << x - 2 << ", " << y << ")" << std::endl;
                }
                std::cout << " ";
                if (!GotoPos(x - 2, ++y)) {
                    std::cerr << "GotoPos failed at (" << x - 2 << ", " << y << ")" << std::endl;
                }
                std::cout << ">";
                Sleep(100);
            }
            break;
        case KEY::SPACE:
            if (y == originy)
                return MENU::START;
            else if (y == originy + 1)
                return MENU::INFO;
            else if (y == originy + 2)
                return MENU::QUIT;
        }
    }
}

KEY TitleScene::KeyController() {
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        return KEY::UP;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        return KEY::DOWN;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        Sleep(50);
        return KEY::SPACE;
    }
    return KEY::FALE;
}