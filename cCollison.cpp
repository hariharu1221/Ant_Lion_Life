#include "DXUT.h"
#include "cCollison.h"

cCollison::cCollison(vector<cBullet*>& bullet, vector<mob_1*>& mob, TileMap* player, int centerboss)
	:m_bullet(bullet), m_mob(mob), m_player(player), centerboss(centerboss)
{
}

cCollison::~cCollison()
{
}

void cCollison::Update(int bosspatern)
{
	MPColl();
	MBPColl();
	if (centerboss != 0) BMPColl();
	BPTColl(bosspatern);
}

void cCollison::MPColl()
{
	for (auto iter = m_mob.begin(); iter != m_mob.end();)
	{
		if (7 + (*iter)->size >= D3DXVec2Length(&(m_player->pos - (*iter)->mob_p)) && m_player->cell[m_player->cc.x][m_player->cc.y] == 1)
		{
			m_player->stop_pos = m_player->pos;
			m_player->hp -= 1;
			m_player->damage = true;
			m_player->pos = m_player->first;
			m_player->IsDrawing = true;
			m_player->DrawArea(3);
		}
		iter++;
	}
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

void cCollison::BMPColl()
{
	if (7 + centerboss >= D3DXVec2Length(&(m_player->pos - CENTER)) && m_player->cell[m_player->cc.x][m_player->cc.y] == 1)
	{
		m_player->stop_pos = m_player->pos;
		m_player->hp -= 1;
		m_player->damage = true;
		m_player->pos = m_player->first;
		m_player->IsDrawing = true;
		m_player->DrawArea(3);
	}
}

void cCollison::BPTColl(int bosspatern)
{
	if (bosspatern == 0)
	{
		colsize = 1;
	}
	if (bosspatern == 1)
	{
		colsize += Delta * 20;
		if (7 + colsize >= D3DXVec2Length(&(m_player->pos - Vec2(855, 610))) && m_player->cell[m_player->cc.x][m_player->cc.y] == 1)
		{
			m_player->stop_pos = m_player->pos;
			m_player->hp -= 1;
			m_player->damage = true;
			m_player->pos = m_player->first;
			m_player->IsDrawing = true;
			m_player->DrawArea(3);
		}
	}
	if (bosspatern == 2)
	{
		colsize += Delta * 250;
		if (7 + colsize >= D3DXVec2Length(&(m_player->pos - Vec2(1085, 610))) && m_player->cell[m_player->cc.x][m_player->cc.y] == 1)
		{
			m_player->stop_pos = m_player->pos;
			m_player->hp -= 1;
			m_player->damage = true;
			m_player->pos = m_player->first;
			m_player->IsDrawing = true;
			m_player->DrawArea(3);
		}
	}
}