#include "TitleScene.h"
#include "console.h"
#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <mmsystem.h>
#include <sstream>  // 추가된 헤더
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void centerText(const std::string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    int x = (columns - text.length()) / 2;
    int y = rows / 2;
    gotoxy(x, y);
}

bool TitleScene::Init() {
    return true;
}

SceneState TitleScene::Update()
{
    //PlaySound("", 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    return { false, false, SceneTypeEnum::InGame };
}

void TitleScene::Render()
{
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
        MenuRender();

        // 잠시 대기하여 출력 확인
        Sleep(3000);

        MENU eMenu = MenuRender();

        switch (eMenu) {
        case MENU::START:
            // Clear the console and print "Hi"
            system("cls");
            std::cout << "Hi" << std::endl;
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
    std::cout << "[조작법]" << std::endl;
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
            {
                system("cls");
                for (int i = 0; i <= 100; i++) {
                    system("cls");
                    std::stringstream ss;
                    ss << i << "% 로딩중. . .";
                    std::string loadingMessage = ss.str();
                    centerText(loadingMessage);
                    std::cout << loadingMessage;
                    Sleep(30);
                }
                system("cls");
                std::string completeMessage = "100% 로딩완료";
                centerText(completeMessage);
                std::cout << completeMessage;
            }

            else if (y == originy + 1)
            {
                system("cls");
                std::cout << "제작: 심장훈, 김민성" << std::endl;
                std::cout << "게임 이름 : ZeroSave" << std::endl;
            }

            else if (y == originy + 2)
            {
                system("cls");
                std::cout << "안녕히가세요";
                exit(1);
            }
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