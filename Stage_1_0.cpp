#include "DXUT.h"
#include "Stage_1_0.h"

Stage_1_0::Stage_1_0()
{
}

Stage_1_0::~Stage_1_0()
{
}

void Stage_1_0::Init()
{
	srand(time(NULL));
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->m_bullets);
	boss = new boss_1(bullet->m_bullets);
	tile = new TileMap(bullet->m_bullets);
	tile->Init();
	coll = new cCollison(bullet->m_bullets, tile);
	mob[0] = new mob_2(bullet->m_bullets, { 400, 300 });
	mob[1] = new mob_2(bullet->m_bullets, { 1700, 200 });
	mob[2] = new mob_2(bullet->m_bullets, { 500, 700 });
	mob[3] = new mob_2(bullet->m_bullets, { 1600, 800 });
}

void Stage_1_0::Update()
{
	tile->Update();
	player->Update(tile->pos);
	boss->Update(tile->pos);
	for (int i = 0; i < 4; i++)
	{
		mob[i]->Update(tile->pos, tile->cell);
		if (tile->cell[int(mob[i]->mob_p.x)][int(mob[i]->mob_p.y)] == 3)
			delete mob[i];
	}
	bullet->Update();
	coll->Update();
}

void Stage_1_0::Render()
{
	tile->Render();
	player->Render();
}

void Stage_1_0::UIRender()
{
	tile->UIRender();
	player->UIRender(tile->pos);
	boss->UIRender();
	for (int i = 0; i < 4; i++) mob[i]->UIRender(); //i 메모리 조절
	bullet->Render();
}

void Stage_1_0::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(tile);
	SAFE_DELETE(boss);
	SAFE_DELETE(coll);
	for (int i = 0; i < 4; i++)
	{
		//delete mob[i];
		SAFE_DELETE(mob[i]);
	}
}