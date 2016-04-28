#include "GameControl.h"
#include <stdio.h>
void MouseLClickEvent(POINT p, int type) {
	int x = p.x;
	int y = p.y;
	if (x >= gbX && x <= (gbW + gbX) && y >= gbY && y <= (gbH + gbY)) {
		int my = (x - gbX) / gbEachWidth;
		int mx = (y - gbY) / gbEachWidth;
		/*char chx[256];
		char chy[256];
		sprintf_s(chx, "%ld", mx);
		sprintf_s(chy, "%ld", my);
		OutputDebugString(chx);
		OutputDebugString(" ");
		OutputDebugString(chy);
		OutputDebugString("\n");*/
		//gameDisplayMap[mx][my] = 1;
		
		if (type == 0) {
			//�������ĵ���¼�
			if (gameHideMap[mx][my] == -1) {
				MessageBox(NULL, TEXT("ʧ��!"), TEXT("���"), MB_ICONINFORMATION | MB_OK);
				initData();
				isGameOver = false;
				isVictory = false;
			} else {
				openMap(mx, my);
			}
		} else if (type == 1){
			//����Ҽ��ĵ���¼�
			if (gameDisplayMap[mx][my] == 2) {
				gameDisplayMap[mx][my] = 0;
			} else {
				gameDisplayMap[mx][my] = 2;
			}
			bool flag = judgeVictory();
			if (flag) {
				MessageBox(NULL,TEXT("���ʤ��"),TEXT("���"),MB_ICONINFORMATION|MB_OK);
				initData();
				isGameOver = false;
				isVictory = false;
			} else {
				OutputDebugString("false\n");
			}
		}
	}
}

bool judgeVictory() {
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameDisplayMap[i][j] == 2 && gameHideMap[i][j] == -1) {
				count++;
			}
			if (gameDisplayMap[i][j] == 2 && gameHideMap[i][j] != -1) {
				return false;
			}
		}
	}
	if (count == mineCount) {
		return true;
	}
	return false;
}