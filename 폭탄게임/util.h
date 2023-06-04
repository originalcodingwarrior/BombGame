#include "main.h"


#ifndef __COLOR_LIST_
#define __COLOR_LIST_

//숫자 입력하지 않고 편리하게 사용하기 위해 열거형으로 정의
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