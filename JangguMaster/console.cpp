#include "Console.h"

void SetPos(int x, int y)
{
	HANDLE hout;
	COORD cur;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(hout, cur);
}

void setColor(int color, int backgroundColor )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backgroundColor << 4) | color);
}

void fullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cs_buf;
	GetConsoleScreenBufferInfo(handle, &cs_buf);
	COORD pos;
	pos.X = cs_buf.srWindow.Right - cs_buf.srWindow.Left + 1;
	pos.Y = cs_buf.srWindow.Bottom - cs_buf.srWindow.Top + 1;
	SetConsoleScreenBufferSize(handle, pos);
}

void FixScreenSize()
{
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	RECT rect;
	GetWindowRect(console, &rect);
}

void AsciiCode(bool check)
{
	if(check) _setmode(_fileno(stdout), _O_U8TEXT);
	else _setmode(_fileno(stdout), _O_TEXT);
}