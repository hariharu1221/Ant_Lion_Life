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
	timer = 0;
	s1ready = false;
	s2ready = false;
	s3ready = false;
	s4ready = false;

	if (notebook)
	{
		aa = 0.5;
	}
}

void SelectScene::Update()
{
	if (option == false)
	{
		if (INPUT->KeyDown(VK_RIGHT) && select < 4) { select++; }
		if (INPUT->KeyDown(VK_LEFT) && select > 1) { select--; }
		switch (select)
		{
		case 1:
			if (INPUT->KeyDown(VK_RETURN))
				s1ready = true;
			break;
		case 2:
			if (INPUT->KeyDown(VK_RETURN))
				s2ready = true;
			break;
		case 3:
			if (INPUT->KeyDown(VK_RETURN))
				s3ready = true;
			break;
		case 4:
			if (INPUT->KeyDown(VK_RETURN))
				s4ready = true;
			break;
		}
		if (INPUT->KeyDown(VK_RETURN) && notebook == false)
			RENDER->TojSize(2, 1, 3);
		if (INPUT->KeyDown(VK_RETURN) && notebook)
			RENDER->TojSize(3, 1, 3);
	}

	if (s1ready)
	{
		if (timer <= 1)
			RENDER->PlusCamPos(Vec3(-5 * (1 + timer) * aa, 2 * (1 + timer) * aa, 0));
		if (timer >= 1)
			SCENE->ChangeScene("Stage_1_0");
			timer += Delta;
	}
	if (s2ready)
	{
		if (timer <= 1)
			RENDER->PlusCamPos(Vec3(-4 * (1 + timer) * aa, -3.5 * (1 + timer) * aa, 0));
		if (timer >= 1)
			SCENE->ChangeScene("Stage_1_1");
			timer += Delta;
	}
	if (s3ready)
	{
		if (timer <= 1)
			RENDER->PlusCamPos(Vec3(3.5 * (1 + timer) * aa, -1.8 * (1 + timer) * aa, 0));
		if (timer >= 1)
			SCENE->ChangeScene("Stage_2_0");
			timer += Delta;
	}
	if (s4ready)
	{
		if (timer <= 1)
			RENDER->PlusCamPos(Vec3(7 * (1 + timer) * aa, 1.8 * (1 + timer) * aa, 0));
		if (timer >= 1)
			SCENE->ChangeScene("Stage_3_0");
			timer += Delta;
	}
}

void SelectScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("selectS"), CENTER, 1.2);
	if (select == 1) RENDER->CenterRender(IMAGE->FindImage("ping"), Vec2(511, 320), 0.1);
	if (select == 2) RENDER->CenterRender(IMAGE->FindImage("ping"), Vec2(607, 775), 0.1);
	if (select == 3) RENDER->CenterRender(IMAGE->FindImage("ping"), Vec2(1182, 615), 0.1);
	if (select == 4) RENDER->CenterRender(IMAGE->FindImage("ping"), Vec2(1473, 318), 0.1);
}

void SelectScene::UIRender()
{
	UI->CenterRender2(IMAGE->FindImage("black"), Vec2(0, 0), 1, (timer) * 255);
}

void SelectScene::Release()
{
}
