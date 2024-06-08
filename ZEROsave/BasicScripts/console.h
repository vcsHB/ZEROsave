#pragma once
#include <iostream>
#include <Windows.h>
using std::cout;
using std::wcout;
using std::endl;

void FullScreen();
BOOL GotoPos(int _x, int _y);
COORD CursorPos();
void SetCursorVisual(bool _vis, DWORD _size);
void SetColor(int _textColor = 15, int _bgColor = 0);
int GetColor();
void LockResize();
COORD GetConsoleResolution();
void SetFontsize(UINT _weight, UINT _sizeX, UINT _sizeY);

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};