#pragma once
#include "DXUT.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "TileMap.h"
#include "cCollison.h"
#include "boss_2.h"
#include "mob_2.h"

class Stage_1_0 :
	public cScene
{
	cPlayer* player = nullptr;
	cBulletAdmin* bullet = nullptr;
	TileMap* tile = nullptr;
	cCollison* coll = nullptr;
	boss_2* boss = nullptr;
	vector<mob_1*> mob;

	int stage = 0;
public:

	Stage_1_0();
	virtual ~Stage_1_0();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();
	virtual void M_Destroy();
};