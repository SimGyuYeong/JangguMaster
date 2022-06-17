#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>

#include "Direction.h"
#include "Janggu.h"
#include "Option.h"

//아스키코드
#include <io.h>
#include <fcntl.h>

//사운드
#include <mmsystem.h>
#include <Digitalv.h>
#include "resource.h"

#pragma comment(lib,"winmm.lib") //링커->입력 에 라이브러리 추가
using namespace std;

//색코드 정의
#define	BLACK 0
#define BLUE 1
#define GREEN 2
#define B_GREEN 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define W_BLUE 9
#define W_GREEN 10
#define W_B_GREEN 11
#define W_RED 12
#define W_PURPLE 13
#define W_YELLOW 14
#define LIGHT_WHITE 15

//BGM 플레이
void PlayingBgm(); 
//효과음 플레이
void PlayingEffect(); 

//출력 좌표설정
void SetPos(int x, int y);
//출력 색설정
void SetColor(int color, int backgroundColor = BLACK);
//전체화면모드
void fullScreen();
void FixScreenSize();

void AsciiCode(bool check);