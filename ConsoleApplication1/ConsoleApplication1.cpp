// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int map[16][16];
int dMap[16][16];

void openMap(int x, int y);

int _tmain(int argc, _TCHAR* argv[]) {
	
	/*for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			map[i][j] = 0;
			dMap[i][j] = 0;
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < 40; i++) {
		int x = rand() % 16;
		int y = rand() % 16;
		if (map[x][y] == -1) {
			i--;
			continue;
		}
		map[x][y] = -1;
	}
	printf("======================\n");
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			int count = 0;
			if (map[i][j] == -1) continue;
			//еп╤овСио
			int x = i - 1;
			int y = j - 1;
			if (x >= 0 && y >= 0 && map[x][y] == -1) {
				count++;
			}
			//еп╤оио
			x = i - 1;
			if (x >= 0 && map[x][j] == -1) {
				count++;
			}
			//еп╤осрио
			x = i - 1;
			y = j + 1;
			if (x >= 0 && y < 16 && map[x][y] == -1) {
				count++;
			}
			//еп╤овС
			y = j - 1;
			if (y >= 0 && map[i][y] == -1) {
				count++;
			}
			//еп╤оср
			y = j + 1;
			if (y <= 16 && map[i][y] == -1) {
				count++;
			}
			//еп╤овСоб
			x = i + 1;
			y = j - 1;
			if (x <= 16 && y >= 0 && map[x][y] == -1) {
				count++;
			}
			//еп╤ооб
			x = i + 1;
			if (x <= 16 && map[x][j] == -1) {
				count++;
			}
			//еп╤осроб
			x = i + 1;
			y = j + 1;
			if (x <= 16 && j <= 16 && map[x][y] == -1) {
				count++;
			}
			map[i][j] = count;
		}
	}
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("%d  %d\n", a, b);
	openMap(a, b);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (dMap[i][j] == 1) {
				printf("%d ", map[i][j]);
			} else {
				printf("x ");
			}
		}
		printf("\n");
	}
	system("pause");*/
	int **t;
	t = (int**)malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; i++) {
		t[i] = (int*)malloc(sizeof(int) * 3);
	}
	t[2][2] = 5;
	printf("%d\n", t[2][2]);
	system("pause");
	return 0;
}


void openMap(int x, int y) {
	if (x < 0 || x >= 16 || y < 0 || y >= 16) {
		return;
	}
	if (dMap[x][y] == 1) {
		return;
	}
	if (map[x][y] != 0) {
		dMap[x][y] = 1;
		return;
	}
	dMap[x][y] = 1;
	//вСио
	if (map[x - 1][y - 1] != 0 && dMap[x-1][y-1] == 0) {
		dMap[x - 1][y - 1] = 1;
	} else if (map[x - 1][y - 1] == 0 && dMap[x - 1][y - 1] == 0) {
		openMap(x - 1, y - 1);
	}

	//ио
	if (map[x - 1][y] != 0 && dMap[x - 1][y] == 0) {
		dMap[x - 1][y] = 1;
	} else if (map[x - 1][y] == 0 && dMap[x - 1][y] == 0) {
		openMap(x - 1, y);
	}
	//срио
	if (map[x - 1][y + 1] != 0 && dMap[x - 1][y + 1] == 0) {
		dMap[x - 1][y - 1] = 1;
	} else if (map[x - 1][y + 1] == 0 && dMap[x - 1][y + 1] == 0) {
		openMap(x - 1, y + 1);
	}
	//вС
	if (map[x][y - 1] != 0 && dMap[x][y - 1] == 0) {
		dMap[x][y - 1] = 1;
	} else if (map[x][y - 1] == 0 && dMap[x][y - 1] == 0) {
		openMap(x, y - 1);
	}
	//ср
	if (map[x][y + 1] != 0 && dMap[x][y + 1] == 0) {
		dMap[x][y + 1] = 1;
	} else if (map[x][y + 1] == 0 && dMap[x][y + 1] == 0) {
		openMap(x, y + 1);
	}
	//вСоб
	if (map[x + 1][y - 1] != 0 && dMap[x + 1][y - 1] == 0) {
		dMap[x + 1][y - 1] = 1;
	} else if (map[x + 1][y - 1] == 0 && dMap[x + 1][y - 1] == 0) {
		openMap(x + 1, y - 1);
	}
	//об
	if (map[x + 1][y] != 0 && dMap[x + 1][y] == 0) {
		dMap[x + 1][y] = 1;
	} else if (map[x + 1][y] == 0 && dMap[x + 1][y] == 0) {
		openMap(x + 1, y);
	}
	//сроб
	if (map[x + 1][y + 1] != 0 && dMap[x + 1][y+1] == 0) {
		dMap[x + 1][y + 1] = 1;
	} else if (map[x + 1][y + 1] == 0 && dMap[x + 1][y + 1] == 0) {
		openMap(x + 1, y + 1);
	}
}