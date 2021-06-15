#include "DXUT.h"
#include "cCollison.h"

cCollison::cCollison(vector<cBullet*>& bullet, TileMap* player)
	:m_bullet(bullet), m_player(player)
{
}

cCollison::~cCollison()
{
}

void cCollison::Update()
{
	MPColl();
	MBPColl();
}

void cCollison::MPColl()
{

}

void cCollison::MBPColl()
{
	for (auto iter = m_bullet.begin(); iter != m_bullet.end();)
	{
		if ((*iter)->bulletType == "mob")
		{
			if (7 + (*iter)->size >= D3DXVec2Length(&(m_player->pos - (*iter)->m_pos)) && m_player->cell[m_player->cc.x][m_player->cc.y] == 1)
			{
				m_player->stop_pos = m_player->pos;
				m_player->hp -= (*iter)->m_Damage;
				m_player->damage = true;
				m_player->pos = m_player->first;
				m_player->IsDrawing = true;
				m_player->DrawArea(3);
				//PART->AddParticle((*iter)->m_pos, 0.3);
				(*iter)->isDestroy = true;
			}
		}
		iter++;
	}
}