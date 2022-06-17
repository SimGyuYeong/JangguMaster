#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>

#include "Direction.h"
#include "Janggu.h"
#include "Option.h"

//�ƽ�Ű�ڵ�
#include <io.h>
#include <fcntl.h>

//����
#include <mmsystem.h>
#include <Digitalv.h>
#include "resource.h"

#pragma comment(lib,"winmm.lib") //��Ŀ->�Է� �� ���̺귯�� �߰�
using namespace std;

//���ڵ� ����
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

//BGM �÷���
void PlayingBgm(); 
//ȿ���� �÷���
void PlayingEffect(); 

//��� ��ǥ����
void SetPos(int x, int y);
//��� ������
void SetColor(int color, int backgroundColor = BLACK);
//��üȭ����
void fullScreen();
void FixScreenSize();

void AsciiCode(bool check);