#include "DXUT.h"
#include "cMBullet.h"

cMBullet::cMBullet(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	bulletType = "mob";
}

cMBullet::~cMBullet()
{
}

void cMBullet::Update()
{
	m_pos += m_Dir * 300 * Delta * float(m_speed / 500);
	m_angle = atan2(m_Dir.y, m_Dir.x);
	timer += Delta;
	if (timer > 0.2)
	{
		count++;
		if (count == 4)
			count = 0;
		timer = 0;
	}
}

void cMBullet::Render()
{
	RENDER->CenterRender(m_ani[count], m_pos, 1, m_angle);
}
