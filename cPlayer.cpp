#include "DXUT.h"
#include "cPlayer.h"
#include "cPBullet.h"

cPlayer::cPlayer(vector<cBullet*>& bullet)
	:m_bullet(bullet)
{
	m_Hp = SCENE->m_Hp;
	m_MaxHp = SCENE->m_MaxHp;
	m_Score = SCENE->m_Score;
}

cPlayer::~cPlayer()
{
	SAFE_DELETE(playerAS);
	SCENE->m_Hp = m_Hp;
	SCENE->m_MaxHp = m_MaxHp;
	SCENE->m_Score = m_Score;
}

void cPlayer::Update(Vec2 m_pos)
{
	if (m_Hp <= 0)
		SCENE->ChangeScene("EndScene");
	if (playerAS) playerAS->Update();
	Move();
	FireBullet(m_pos);
	ItemUpdate();
	SCENE->v_pos = m_pos;
}

void cPlayer::Render()
{

}

void cPlayer::UIRender(Vec2 m_pos)
{
	UI->CenterRender(IMAGE->FindImage("player"), Vec2(m_pos.x, m_pos.y));
	for (int i = 0; i < m_Hp; i++)
	{
		//UI->CenterRender(IMAGE->FindImage("hp"), Vec2(62.5 + i * 74, 824.5));
	}
	UI->CenterRender(IMAGE->FindImage("hp_hl"), Vec2(249.25, 825.5));
}

void cPlayer::Move()
{
	
}

void cPlayer::FireBullet(Vec2 m_pos)
{
	if (INPUT->KeyPress(90) && b_fire)
	{
		m_bullet.push_back(new cPBullet(m_pos));
		playerAS = new cTimer(0.1, [&]()->void { b_fire = true; playerAS = nullptr; });
		b_fire = false;
	}
}

void cPlayer::ItemUpdate()
{
	if (m_Hp >= 6) m_Hp = 6;
	if (ItemName == "Heal")
	{
		m_Hp += 2;
		ItemName = "none";
	}
}
