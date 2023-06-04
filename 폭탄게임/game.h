#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0 //WŰ
#define DOWN 1 //SŰ
#define LEFT 2 //AŰ
#define RIGHT 3 //DŰ
#define SUBMIT 4 //SPACEŰ

#endif

int gLoop();
void move(int*, int*, int, int, int*);
int keyControl();
int menuDraw();
void infoDraw();
int drawMap(int*, int*);
void drawUI(int);
int gamestop();
void timer();
void BAD_Ending();
void HAPPY_Ending();
void NORMAL_Ending_1();
void NORMAL_Ending_2();
void What_Ending(int, int);
void Opening();