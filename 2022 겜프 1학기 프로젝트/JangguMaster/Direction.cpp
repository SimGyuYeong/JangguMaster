#include "Direction.h"
#include "console.h"

const wstring GyulGames[] =
{
	L"   ___      _  _                  _                  ___                                            ",
	L"  / __|    | || |     _  _       | |       ___      / __|     __ _      _ __        ___       ___   ",
	L"  |(_ |      \_, |    | +| |      | |      |___|     |(_ |    / _` |    | '  \      / -_)     (_-<    ",
	L"   \___|    _|__/       \_,_|     _|_|_     _____      \___|     \__,_|    |_|_|_|     \___|     /__/_   ",
	L"_|'''''| _ |'''''| _ |'''''| _ |'''''| _ |     | _ |'''''| _ |'''''| _ |'''''| _ |'''''| _ |'''''|  ",
	L" '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'   '-0-0-'  "
};

const wstring GameTitle[] =
{
	L"███╗███╗   ███╗███╗         ",
	L"██╗ █████╗ ███╗   ██╗ ██████╗  ██████╗ ██╗   ██╗",
	L"██╔╝████╗ ████║╚██║         ",
	L"██║██╔══██╗████╗  ██║██╔════╝ ██╔════╝ ██║   ██║",
	L"██║ ██╔████╔██║ ██║         ",
	L"██║███████║██╔██╗ ██║██║  ███╗██║  ███╗██║   ██║",
	L"██║ ██║╚██╔╝██║ ██║    ",
	L"██   ██║██╔══██║██║╚██╗██║██║   ██║██║   ██║██║   ██║",
	L"███╗██║ ╚═╝ ██║███║    ",
	L"╚█████╔╝██║  ██║██║ ╚████║╚██████╔╝╚██████╔╝╚██████╔╝",
	L"╚══╝╚═╝     ╚═╝╚══╝     ",
	L"╚════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝  ╚═════╝ "
};

void GyulGamesLogoView()
{
	AsciiCode(true);

	int max = 40 + size(GyulGames[0]) - 1;
	int i = 0;
	for (int j = 0; j < size(GyulGames[0]) - 35; j++)
	{
		for (i = 0 + j; i < size(GyulGames[0]) - j; i++)
		{
			SetPos(40 + i - j, 20);
			wcout << GyulGames[0][i + j];
			SetPos(40 + i - j, 21);
			wcout << GyulGames[1][i + j];
			SetPos(40 + i - j, 22);
			wcout << GyulGames[2][i + j];
			SetPos(40 + i - j, 23);
			wcout << GyulGames[3][i + j];
			SetPos(40 + i - j, 24);
			wcout << GyulGames[4][i + j];
			SetPos(40 + i - j, 25);
			wcout << GyulGames[5][i + j];
			if (j == 0)
				Sleep(50);
		}

		if (j == 0)
		{
			for (int k = 0; k < size(GyulGames); k++)
			{
				if (k == 0) setColor(YELLOW);
				else if (k == 4) setColor(B_GREEN);
				SetPos(40, 20 + k);
				wcout << GyulGames[k];
				Sleep(100);
			}

			Sleep(200);

			for (int k = 0; k < size(GyulGames); k++)
			{
				setColor(WHITE);
				SetPos(40, 20 + k);
				wcout << GyulGames[k];
				Sleep(100);
			}
		}

		SetPos(41 + i - j, 20);
		wcout << ' ';
		SetPos(41 + i - j, 21);
		wcout << ' ';
		SetPos(41 + i - j, 22);
		wcout << ' ';
		SetPos(41 + i - j, 23);
		wcout << ' ';
		SetPos(41 + i - j, 24);
		wcout << ' ';
		SetPos(41 + i - j, 25);
		wcout << ' ';
		Sleep(100);
	}

	AsciiCode(false);
}

void TitleLogoView(bool skip)
{
	system("cls");
	AsciiCode(true);

	for (int i = 0; i < size(GameTitle); i++)
	{
		if (i % 2 == 0)
		{
			SetPos(60, 12 + i / 2);
			setColor(YELLOW);
			if(skip==true)
				Sleep(100);
		}
		else
			setColor(W_GREEN);

		wcout << GameTitle[i];
	}

	AsciiCode(false);
	setColor(WHITE);
}

void TitleLogoHide()
{
	for (int i = 10; i < 30; i++)
	{
		SetPos(50, i);
		cout << "	                                                                                      ";
		Sleep(50);
	}
}

void Loading(Level level)
{

}

void SubTitle(string text)
{
	if (text == "ModeSelect")
	{
	}
}


