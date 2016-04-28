#pragma once
#include "GameEntity.h"
#include <Wincodec.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
class GameLayer {
public:
	GameLayer();
	~GameLayer();

	void OnRender(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush * brush, IDWriteTextFormat* m_pTextFormat, ID2D1SolidColorBrush* fontBrush);
};

