#pragma once

enum Action
{
	Start = 1,
	Exit
};

enum Level
{
	Easy = 1,
	Normal,
	Hard
};

void ActionSelectView();
void ActionSelect();

void LevelSelectView();
void LevelSelect();

