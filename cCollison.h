#pragma once
#include "cBullet.h"
#include "mob_1.h"
#include "TileMap.h"
class cCollison
{
public:
	cCollison(vector<cBullet*>& bullet, vector<mob_1*>& mob, TileMap* m_player, int centerboss = 0);
	~cCollison();

	vector<cBullet*>& m_bullet;
	vector<mob_1*>& m_mob;
	TileMap* m_player;

	bool b_PMcoll = true;
	int centerboss;

	void Update();

	void MPColl();
	void MBPColl();
	void BMPColl();
};

