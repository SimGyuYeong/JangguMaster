#include "console.h"

#pragma region 사운드 정의

MCI_OPEN_PARMS OpenBgm; //BGM 여는 용도
MCI_PLAY_PARMS PlayBgm; //BGM 실행할 용도

MCI_OPEN_PARMS OpenEffect; //효과음 여는 용도
MCI_PLAY_PARMS PlayEffect; //효과음 실행할 용도

UINT dwBgmID; //Device ID
UINT dwEffectID; //Device ID

void PlayingBgm()
{
	//TEXT("내용") == L("내용")
	OpenBgm.lpstrElementName = TEXT("Sakuranbo.wav");
	OpenBgm.lpstrDeviceType = TEXT("waveaudio");

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID) & OpenBgm);
	dwBgmID = OpenBgm.wDeviceID;
	mciSendCommand(dwBgmID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&PlayBgm);
}

void StopBgm()
{
	/*mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&OpenBgm);
	dwID = OpenBgm.wDeviceID;*/
	mciSendCommand(dwBgmID, MCI_CLOSE, 0, NULL);
}

void PlayingEffect(LPCWSTR name)
{
	//처음위치로 이동
	mciSendCommand(dwEffectID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&PlayEffect);

	OpenEffect.lpstrElementName = name;
	OpenEffect.lpstrDeviceType = L"waveaudio";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&OpenEffect);
	dwEffectID = OpenEffect.wDeviceID;
	mciSendCommand(dwEffectID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&PlayEffect);
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

void CursorView() {
	CONSOLE_CURSOR_INFO curinfo;
	
	curinfo.dwSize = 1;
	curinfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}