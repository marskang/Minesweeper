#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

extern int row;
extern int col;
extern int mineCount;
extern int gbEachWidth;
extern int gbPadding;
extern int gbX;
extern int gbY;
extern int gbW;
extern int gbH;
extern int **gameHideMap;
extern int **gameDisplayMap;
extern bool isGameOver;
extern bool isVictory;

void initData();