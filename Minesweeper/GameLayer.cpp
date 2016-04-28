#include "GameLayer.h"


GameLayer::GameLayer() {
}


GameLayer::~GameLayer() {
}

void GameLayer::OnRender(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush * brush, IDWriteTextFormat* m_pTextFormat, ID2D1SolidColorBrush* fontBrush) {
	D2D1_RECT_F rect = D2D1::RectF(90, 90, 100, 100);
	ID2D1SolidColorBrush * grayBrush;
	ID2D1SolidColorBrush * bannerBrush;
	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0x595656, 1.0f), &grayBrush);
	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0xb40000, 1.0f), &bannerBrush);
	for (int i = 0; i < col; i++) {
		int x = gbEachWidth * i + gbX;
		for (int j = 0; j < row; j++) {
			int y = gbEachWidth * j + gbY;
			int right = x + gbEachWidth - gbPadding;
			int bottom = y + gbEachWidth - gbPadding;
			rect = D2D1::RectF(x, y, right, bottom);
			if (gameDisplayMap[j][i] == 1) {
				pRenderTarget->FillRectangle(&rect, grayBrush);
				D2D1_RECT_F rectFont = D2D1::RectF(x + 3, y - 2, right, bottom);
				WCHAR z = gameHideMap[j][i] + 48;
				WCHAR num[2];
				num[0] = z;
				num[1] = '\0';
				pRenderTarget->DrawTextA(
					num,
					ARRAYSIZE(num) - 1,
					m_pTextFormat,
					rectFont,
					fontBrush);
			} else if (gameDisplayMap[j][i] == 2) {
				pRenderTarget->FillRectangle(&rect, brush);
				D2D1_RECT_F rectFont = D2D1::RectF(x + 3, y - 2, right, bottom);
				WCHAR num[2] = L"x";
				pRenderTarget->DrawTextA(
					num,
					ARRAYSIZE(num) - 1,
					m_pTextFormat,
					rectFont,
					fontBrush);
			} else {
				pRenderTarget->FillRectangle(&rect, brush);
			}
		}
	}
	fontBrush->SetColor(D2D1::ColorF(0xfcff00, 1.0f));
	grayBrush->Release();
	bannerBrush->Release();
	//pRenderTarget->CreateSolidColorBrush
}
