#pragma once
#include "DXUT.h"
class SelectScene
	:public cScene
{
public:
	int select = 1;
	int optionS = 1;
	bool option = 0;
	bool bop = false;
	bool set = false;

	SelectScene();
	virtual ~SelectScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();

};

