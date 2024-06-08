#include <Windows.h>
#include "console.h"

void FullScreen() {
	/*SetConsoleDisplayMode
	(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE, NULL);*/

	ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);

	/*::SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN,
		VK_RETURN, 0x20000000);*/

}

BOOL GotoPos(int _x, int _y) {
	// 콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 커서 관련 구조체
	COORD Cursor = { _x, _y }; // _x * 2가 자연스러울 수도 있음
	// 콘솔 커서의 위치를 강제 이동시키는 함수
	return SetConsoleCursorPosition(hOut, Cursor);
}

COORD CursorPos() {
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &Buf);

	return Buf.dwCursorPosition;
}

void SetCursorVisual(bool _vis, DWORD _size) {

	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = _vis; // on/ off
	curInfo.dwSize = _size; // 1 ~ 100
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&curInfo
	);
}

void SetColor(int _textColor, int _bgColor)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		(_bgColor << 4) | _textColor
	);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &Buf);
	int color = Buf.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console) {
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;// &~WS_CAPTION;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;

	return COORD{ width, height };
}

void SetFontsize(UINT _weight, UINT _sizeX, UINT _sizeY) {
	// 굵게. 사이즈 크기는 못키우나요?

	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hOut, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizeX;
	font.dwFontSize.Y = _sizeY;
	SetCurrentConsoleFontEx(hOut, false, &font);
}


