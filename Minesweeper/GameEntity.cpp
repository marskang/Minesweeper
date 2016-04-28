#include "GameEntity.h"

int row = 15;
int col = 16;
int mineCount = 5;

int gbEachWidth = 25;
int gbPadding = 2;
int gbX = 10;
int gbY = 10;
int gbW = col * gbEachWidth;
int gbH = row * gbEachWidth;
bool isGameOver = false;
bool isVictory = false;
int **gameHideMap;
int **gameDisplayMap;

void initData() {
	if (gameDisplayMap == NULL) {
		gameDisplayMap = (int **)malloc(sizeof(int) * row);
	}
	if (gameHideMap == NULL) {
		gameHideMap = (int **)malloc(sizeof(int) * row);
	}
	
	for (int i = 0; i < row; i++) {
		gameHideMap[i] = (int *)malloc(sizeof(int) * col);
		gameDisplayMap[i] = (int *)malloc(sizeof(int) * col);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			gameHideMap[i][j] = 0;
			gameDisplayMap[i][j] = 0;
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < mineCount; i++) {
		int x = rand() % row;
		int y = rand() % col;
		if (gameHideMap[x][y] == -1) {
			i--;
			continue;
		}
		gameHideMap[x][y] = -1;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int count = 0;
			if (gameHideMap[i][j] == -1) continue;
			//еп╤овСио
			int x = i - 1;
			int y = j - 1;
			if (x >= 0 && y >= 0 && gameHideMap[x][y] == -1) {
				count++;
			}
			//еп╤оио
			x = i - 1;
			if (x >= 0 && gameHideMap[x][j] == -1) {
				count++;
			}
			//еп╤осрио
			x = i - 1;
			y = j + 1;
			if (x >= 0 && y < col && gameHideMap[x][y] == -1) {
				count++;
			}
			//еп╤овС
			y = j - 1;
			if (y >= 0 && gameHideMap[i][y] == -1) {
				count++;
			}
			//еп╤оср
			y = j + 1;
			if (y < col && gameHideMap[i][y] == -1) {
				count++;
			}
			//еп╤овСоб
			x = i + 1;
			y = j - 1;
			if (x < row && y >= 0 && gameHideMap[x][y] == -1) {
				count++;
			}
			//еп╤ооб
			x = i + 1;
			if (x < row && gameHideMap[x][j] == -1) {
				count++;
			}
			//еп╤осроб
			x = i + 1;
			y = j + 1;
			if (x < row && j < col && gameHideMap[x][y] == -1) {
				count++;
			}
			gameHideMap[i][j] = count;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char re = gameHideMap[i][j] + 48;
			char re2[2];
			re2[0] = re;
			re2[1] = '\0';
			OutputDebugString(re2);
			OutputDebugString(" ");
		}
		OutputDebugString("\n");
	}
}

void openMap(int x, int y) {
	if (x < 0 || x >= row || y < 0 || y >= col) {
		return;
	}
	if (gameDisplayMap[x][y] == 1) {
		return;
	} 
	if (gameHideMap[x][y] != 0) {
		gameDisplayMap[x][y] = 1;
		return;
	}
	gameDisplayMap[x][y] = 1;
	//вСио
	if (x > 0 && y > 0 && gameHideMap[x - 1][y - 1] != 0 && gameDisplayMap[x - 1][y - 1] != 1) {
		gameDisplayMap[x - 1][y - 1] = 1;
	} else if (x > 0 && y > 0 && gameHideMap[x - 1][y - 1] == 0 && gameDisplayMap[x - 1][y - 1] != 1) {
		openMap(x - 1, y - 1);
	}

	//ио
	if (x > 0 && gameHideMap[x - 1][y] != 0 && gameDisplayMap[x - 1][y] != 1) {
		gameDisplayMap[x - 1][y] = 1;
	} else if (x > 0 && gameHideMap[x - 1][y] == 0 && gameDisplayMap[x - 1][y] != 1) {
		openMap(x - 1, y);
	}
	//срио
	if (x > 0 && y < (col - 1) && gameHideMap[x - 1][y + 1] != 0 && gameDisplayMap[x - 1][y + 1] != 1) {
		gameDisplayMap[x - 1][y + 1] = 1;
	} else if (x > 0 && y < (col - 1) && gameHideMap[x - 1][y + 1] == 0 && gameDisplayMap[x - 1][y + 1] != 1) {
		openMap(x - 1, y + 1);
	}
	//вС
	if (y > 0 && gameHideMap[x][y - 1] != 0 && gameDisplayMap[x][y - 1] != 1) {
		gameDisplayMap[x][y - 1] = 1;
	} else if (y > 0 && gameHideMap[x][y - 1] == 0 && gameDisplayMap[x][y - 1] != 1) {
		openMap(x, y - 1);
	}
	//ср
	if (y < col - 1 && gameHideMap[x][y + 1] != 0 && gameDisplayMap[x][y + 1] != 1) {
		gameDisplayMap[x][y + 1] = 1;
	} else if (y < col - 1 && gameHideMap[x][y + 1] == 0 && gameDisplayMap[x][y + 1] != 1) {
		openMap(x, y + 1);
	}
	//вСоб
	if (x < row - 1 && y > 0 && gameHideMap[x + 1][y - 1] != 0 && gameDisplayMap[x + 1][y - 1] != 1) {
		gameDisplayMap[x + 1][y - 1] = 1;
	} else if (x < row - 1 && y > 0 && gameHideMap[x + 1][y - 1] == 0 && gameDisplayMap[x + 1][y - 1] != 1) {
		openMap(x + 1, y - 1);
	}
	//об
	if (x < row - 1 && gameHideMap[x + 1][y] != 0 && gameDisplayMap[x + 1][y] != 1) {
		gameDisplayMap[x + 1][y] = 1;
	} else if (x < row - 1 && gameHideMap[x + 1][y] == 0 && gameDisplayMap[x + 1][y] != 1) {
		openMap(x + 1, y);
	}
	//сроб
	if (x < row - 1 && y < col - 1 && gameHideMap[x + 1][y + 1] != 0 && gameDisplayMap[x + 1][y + 1] != 1) {
		gameDisplayMap[x + 1][y + 1] = 1;
	} else if (x < row - 1 && y < col - 1 && gameHideMap[x + 1][y + 1] == 0 && gameDisplayMap[x + 1][y + 1] != 1) {
		openMap(x + 1, y + 1);
	}
}