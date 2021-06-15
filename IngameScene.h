#pragma once
#include "DXUT.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "TileMap.h"
#include "cCollison.h"
#include "boss_1.h"

class IngameScene :
	public cScene
{
	cPlayer* player = nullptr;
	cBulletAdmin* bullet = nullptr;
	TileMap* tile = nullptr;
	cCollison* coll = nullptr;
	boss_1* boss = nullptr;

	int stage = 1;
public:

	IngameScene();
	virtual ~IngameScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();
};

