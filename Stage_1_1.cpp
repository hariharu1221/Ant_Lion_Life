#include "DXUT.h"
#include "Stage_1_1.h"

Stage_1_1::Stage_1_1()
{
}

Stage_1_1::~Stage_1_1()
{
}

void Stage_1_1::Init()
{
	srand(time(NULL));
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->m_bullets);
	boss = new boss_1(bullet->m_bullets);
	tile = new TileMap(bullet->m_bullets);
	tile->Init(stage);
	coll = new cCollison(bullet->m_bullets, mob, tile, 200);
	mob.push_back(new mob_1(bullet->m_bullets, { 400, 300 }));
	mob.push_back(new mob_1(bullet->m_bullets, { 1700, 200 }));
	mob.push_back(new mob_1(bullet->m_bullets, { 500, 700 }));
	mob.push_back(new mob_1(bullet->m_bullets, { 1600, 800 }));
}

void Stage_1_1::Update()
{
	player->Update(tile->pos);
	boss->Update(tile->pos);
	for (auto iter = mob.begin(); iter != mob.end(); iter++)	(*iter)->Update(tile->pos, tile->cell);
	M_Destroy();
	bullet->Update();
	coll->Update();
	tile->Update();
}

void Stage_1_1::Render()
{
	tile->Render();
	player->Render();
}

void Stage_1_1::UIRender()
{
	tile->UIRender();
	player->UIRender(tile->pos);
	boss->UIRender();
	for (auto iter : mob) iter->UIRender();
	bullet->Render();
}

void Stage_1_1::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(tile);
	SAFE_DELETE(boss);
	SAFE_DELETE(coll);
	for (auto iter : mob)	SAFE_DELETE(iter);
}

void Stage_1_1::M_Destroy() //몬스터 파괴 및 조건
{
	size_t size = mob.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = mob[i];
		if (tile->cell[int(iter->mob_p.x)][int(iter->mob_p.y)] == 3)
		{
			//SAFE_DELETE(iter);
			mob.erase(mob.begin() + i);
			i--; size--;
		}
	}
}