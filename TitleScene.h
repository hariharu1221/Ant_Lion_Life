#pragma once
#include "DXUT.h"
class TitleScene :
	public cScene
{
public:
	int select = 1;
	int optionS = 1;
	bool option = 0;

	TitleScene();
	virtual ~TitleScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();
};

