#include "DXUT.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	SCENE->PlayerInit();
	set = true;
}

void TitleScene::Update()
{
	if (set)
	{
		SCENE->ResetScnee("Stage_1_0", new Stage_1_0);
		SCENE->ResetScnee("Stage_1_1", new Stage_1_1);
		SCENE->ResetScnee("Stage_2_0", new Stage_2_0);
		SCENE->ResetScnee("Stage_3_0", new Stage_3_0);
	}
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
				SCENE->ChangeScene("Stage_1_0");
			break;
		case 2:
			if (INPUT->KeyDown(VK_RETURN))
				exit(0);
			break;
		case 3:
			if (INPUT->KeyDown(VK_RETURN))
				option = true;
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	else
	{
		if (INPUT->KeyDown(VK_DOWN) && optionS < 2) { optionS++; }
		if (INPUT->KeyDown(VK_UP) && optionS > 1) { optionS--; }
	}
}

void TitleScene::Render()
{
	if (select == 1)
		RENDER->CenterRender(IMAGE->FindImage("start game ready"), CENTER, 1.2);
	if (select == 2)
		RENDER->CenterRender(IMAGE->FindImage("end the game ready"), CENTER, 1.2);
	if (select == 3)
		RENDER->CenterRender(IMAGE->FindImage("how to play ready"), CENTER, 1.2);
	if (select == 4)
		RENDER->CenterRender(IMAGE->FindImage("credit ready"), CENTER, 1.2);
}

void TitleScene::UIRender()
{
}

void TitleScene::Release()
{
}
