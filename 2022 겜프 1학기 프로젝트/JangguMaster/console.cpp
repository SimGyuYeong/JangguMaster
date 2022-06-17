#include "console.h"

#pragma region ���� ����

MCI_OPEN_PARMS OpenBgm; //BGM ���� �뵵
MCI_PLAY_PARMS PlayBgm; //BGM ������ �뵵

MCI_OPEN_PARMS OpenEffect; //ȿ���� ���� �뵵
MCI_PLAY_PARMS PlayEffect; //ȿ���� ������ �뵵

UINT dwID; //Device ID

void PlayingBgm()
{
	//TEXT("����") == L("����")
	OpenBgm.lpstrElementName = TEXT("Sakuranbo.wav");
	OpenBgm.lpstrDeviceType = TEXT("waveaudio");

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID) & OpenBgm);
	dwID = OpenBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&PlayBgm);
}

void PlayingEffect()
{
	//ó����ġ�� �̵�
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&PlayEffect);

	OpenEffect.lpstrElementName = L"pickupCoin.wav";
	OpenEffect.lpstrDeviceType = L"waveaudio";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&OpenEffect);
	dwID = OpenBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&PlayEffect);
}

#pragma endregion

void SetPos(int x, int y)
{
	HANDLE hout;
	COORD cur;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(hout, cur);
}

void SetColor(int color, int backgroundColor )
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