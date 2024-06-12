//#include"console.h"
#include<Windows.h>
#include "TitleScene.h"
#include "console.h"
#include "Define.h"

bool TitleScene::Init() 
{
    return true;
}

SceneState TitleScene::Update()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    cout << "Title Scene Updated" << endl;
    return { false, false, SceneTypeEnum::InGame };
}

void TitleScene::Render()
{
    GotoPos(0, 0);
    wcout << R"(
       

                     ________  ________  _______    ______    ______    ______   __     __  ________ 
                    |        \|        \|       \  /      \  /      \  /      \ |  \   |  \|        \
                    \$$$$$$$$| $$$$$$$$| $$$$$$$\|  $$$$$$\|  $$$$$$\|  $$$$$$\| $$   | $$| $$$$$$$$
                       /  $$ | $$__    | $$__| $$| $$  | $$| $$___\$$| $$__| $$| $$   | $$| $$__    
                      /  $$  | $$  \   | $$    $$| $$  | $$ \$$    \ | $$    $$ \$$\ /  $$| $$  \   
                     /  $$   | $$$$$   | $$$$$$$\| $$  | $$ _\$$$$$$\| $$$$$$$$  \$$\  $$ | $$$$$   
                    /  $$___ | $$_____ | $$  | $$| $$__/ $$|  \__| $$| $$  | $$   \$$ $$  | $$_____ 
                   |  $$    \| $$     \| $$  | $$ \$$    $$ \$$    $$| $$  | $$    \$$$   | $$     \
                    \$$$$$$$$ \$$$$$$$$ \$$   \$$  \$$$$$$   \$$$$$$  \$$   \$$     \$     \$$$$$$$$
                            
                            
        )" << endl;

    wcout << R"(
                                                   _____ __    _____ __ __ 
                                                  |  _  |  |  |  _  |  |  |
                                                  |   __|  |__|     |_   _|
                                                  |__|  |_____|__|__| |_|  
                     
            )" << endl;

    wcout << R"(
                                                   _____ __ __ _____ _____ 
                                                  |   __|  |  |     |_   _|
                                                  |   __|-   -|-   -| | |  
                                                  |_____|__|__|_____| |_|  

            )" << endl;
    isRendered = true;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y }; //x, y ÁÂÇ¥ ¼³Á¤
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ä¿¼­ ¼³Á¤
}
