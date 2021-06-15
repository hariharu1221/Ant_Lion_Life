#include "DXUT.h"
#include "IngameScene.h"

IngameScene::IngameScene()
{
}

IngameScene::~IngameScene()
{
}

void IngameScene::Init()
{
	srand(time(NULL));
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->m_bullets);
	boss = new boss_1(bullet->m_bullets);
	tile = new TileMap(bullet->m_bullets);
	tile->Init();
	coll = new cCollison(bullet->m_bullets, tile);
}

void IngameScene::Update()
{
	tile->Update();
	player->Update(tile->pos);
	boss->Update(tile->pos);
	bullet->Update();
	coll->Update(); 
}

void IngameScene::Render()
{
	tile->Render();
	player->Render();
}

void IngameScene::UIRender()
{
	tile->UIRender();
	player->UIRender(tile->pos);
	boss->UIRender();
	bullet->Render();
}

void IngameScene::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(tile);
	SAFE_DELETE(boss);
	SAFE_DELETE(coll);
}
