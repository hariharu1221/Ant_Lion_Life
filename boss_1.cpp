#include "DXUT.h"
#include "boss_1.h"
#include "cMBullet.h"

boss_1::boss_1(vector<cBullet*>& bullet)
	:m_bullet(bullet)
{
	
}

boss_1::~boss_1()
{
}

void boss_1::Update(Vec2 m_pos)
{
	Skill(m_pos);
}

void boss_1::Skill(Vec2 m_pos)
{
	frame += Delta * 4;
	if (frame >= m_ani.size())
		frame = 0;

	if (bultime > 0.5) //0.5�ʸ��� �⺻ �ҷ�
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_pos - bpos));
		m_bullet.push_back(new cMBullet(bpos, pos, 1));
		bultime = 0;
	}

	if (skilltime > 5) //3�ʸ��� ���� �ҷ�
	{
		float  angle = 0;
		float  rad = D3DX_PI * 2 / 30;
		for (float i = 0; i < 30; i++, angle += rad)
		{
			Vec2 Direction = Vec2(bpos.x + (cosf(angle) * 5), bpos.y + (sinf(angle) * 5));
			Direction = Direction - bpos;
			D3DXVec2Normalize(&Direction, &Direction);
			m_bullet.push_back(new cMBullet(bpos, Direction, 1));
		}

		skilltime = 0;
	}

	if (busttime > 0.2) //7�ʸ��� 360�� �ҷ�
	{
		float  angle = 0;

		float  rad = D3DX_PI * 2 / 30;
		for (float i = acttime; i < 15.5 + acttime; i++, angle = rad * i)
		{
			Vec2 Direction = Vec2(bpos.x + (cosf(angle) * 5), bpos.y + (sinf(angle) * 5));
			Direction = Direction - bpos;
			D3DXVec2Normalize(&Direction, &Direction);
			m_bullet.push_back(new cMBullet(bpos, Direction, 7));
		}
		busttime = 0;
		acttime++;
		if (acttime == 30) { acttime = 0; busttime = -7; }
	}

	bultime += Delta;
	skilltime += Delta;
	b_time += Delta;
	busttime += Delta;
}

void boss_1::Render()
{
	RENDER->CenterRender(m_ani[int(frame)], CENTER, 2);
}

void boss_1::UIRender()
{
}
