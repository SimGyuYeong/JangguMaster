#include "console.h"
#include "Option.h"
#include "Direction.h"

int main()
{
	FixScreenSize();
	fullScreen();

	//GyulGamesLogoView();
	TitleLogoView(true);
	Sleep(100);
	ActionSelectView();
	setColor(BLACK);
}