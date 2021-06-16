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

	if (bultime > 0.5) //0.5초마다 기본 불렛
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_pos - bpos));
		m_bullet.push_back(new cMBullet(bpos, pos, 1));
		bultime = 0;
	}

	if (skilltime > 5) //3초마다 원형 불렛
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

	bultime += Delta;
	skilltime += Delta;
	b_time += Delta;
}

void boss_1::Render()
{
}

void boss_1::UIRender()
{
	UI->CenterRender(m_ani[int(frame)], CENTER, 2);
}
