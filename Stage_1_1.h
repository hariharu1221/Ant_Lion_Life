#pragma once
#include "DXUT.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "TileMap.h"
#include "cCollison.h"
#include "boss_1.h"
#include "mob_1.h"
#include "mob_2.h"

class Stage_1_1 :
	public cScene
{
	cPlayer* player = nullptr;
	cBulletAdmin* bullet = nullptr;
	TileMap* tile = nullptr;
	cCollison* coll = nullptr;
	boss_1* boss = nullptr;
	mob_1* mob[4] = { nullptr };

	int stage = 1;
public:

	Stage_1_1();
	virtual ~Stage_1_1();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();
};