#include "console.h"

Action action = Start;
Level level = Easy;

void ActionSelectView()
{
	SetPos(86, 25);
	if (action == Start) cout << ">";
	else cout << " ";

	SetPos(86, 26);
	if (action == Exit) cout << ">";
	else cout << " ";

	SetPos(88, 25);
	cout << "게임시작";
	SetPos(88, 26);
	cout << "게임종료";

	ActionSelect();
}

void ActionSelect()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (action == Exit)
		{
			TitleLogoView();
			SetPos(77, 22);
			setColor(W_RED);
			cout << "게임을 종료하시려면 아무키나 눌러주세요.";
			setColor(BLACK);
			return;
		}
		else if (action == Start)
		{
			TitleLogoView();
			LevelSelectView();
			return;
		}
	}

	switch (_getch())
	{
	case 72:
		if (action == Exit)
		{
			action = Start;
		}
		break;
	case 80:
		if (action == Start)
		{
			action = Exit;
		}
		break;
		
	default:
		break;
	}

	ActionSelectView();
}

void LevelSelectView()
{
	SetPos(86, 24);
	setColor(W_YELLOW);
	cout << "| 난이도 선택 |";

	for (int i = 25; i < 28; i++)
	{
		SetPos(88, i);
		if (level == i - 24) cout << ">";
		else cout << " ";
	}

	setColor(WHITE);
	SetPos(90, 25);
	cout << "단조로움";
	SetPos(90, 26);
	cout << "평범함";
	SetPos(90, 27);
	cout << "복잡함";

	LevelSelect();
}

void LevelSelect()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		TitleLogoHide();
		Loading(level);
		return;
	}

	switch (_getch())
	{
	case 72:
		if (level == Hard) level = Normal;
		else if (level == Normal) level = Easy;
		break;
	case 80:
		if (level == Easy) level = Normal;
		else if (level == Normal) level = Hard;
		break;

	default:
		break;
	}

	LevelSelectView();
}
