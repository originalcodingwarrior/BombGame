#include "main.h"


#ifndef __COLOR_LIST_
#define __COLOR_LIST_

//���� �Է����� �ʰ� ���ϰ� ����ϱ� ���� ���������� ����
enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white

};

#endif

void gotoxy(int, int);
void init();
void setColor(int, int);