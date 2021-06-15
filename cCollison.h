#pragma once
#include "cBullet.h"
#include "TileMap.h"
class cCollison
{
public:
	cCollison(vector<cBullet*>& bullet, TileMap* m_player);
	~cCollison();

	vector<cBullet*>& m_bullet;
	TileMap* m_player;

	bool b_PMcoll = true;

	void Update();

	void MPColl();
	void MBPColl();
};

