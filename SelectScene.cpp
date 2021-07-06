#include "DXUT.h"
#include "SelectScene.h"

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::Init()
{
}

void SelectScene::Update()
{
	if (option == false)
	{
		if (INPUT->KeyDown(VK_UP) && select >= 3) { select -= 2; }
		if (INPUT->KeyDown(VK_DOWN) && select <= 2) { select += 2; }
		if (INPUT->KeyDown(VK_RIGHT) && select < 4) { select++; }
		if (INPUT->KeyDown(VK_LEFT) && select > 1) { select--; }
		switch (select)
		{
		case 1:
			if (INPUT->KeyDown(VK_RETURN))
				SCENE->ChangeScene("SelectScene");
			break;
		case 2:
			if (INPUT->KeyDown(VK_RETURN))
				exit(0);
			break;
		case 3:
			break;
		case 4:
			if (INPUT->KeyDown(VK_RETURN))
				option = true;
			break;
		default:
			break;
		}
	}
}

void SelectScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("selectS"), CENTER, 1.2);
}

void SelectScene::UIRender()
{
}

void SelectScene::Release()
{
}
