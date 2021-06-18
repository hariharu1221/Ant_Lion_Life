#include "DXUT.h"
#include "mob_2.h"

mob_2::mob_2(vector<cBullet*>& bullet, Vec2 mob_p)
	: mob_1(bullet, mob_p)
{
	m_ani = IMAGE->MakeVecImg("mob2");
}

mob_2::~mob_2()
{
}

void mob_2::Update(Vec2 m_pos, int cell[][CELLSIZEY])
{
	if (cell[int(mob_p.x)][int(mob_p.y)] == 3)
	{

	}

	Skill();  
}

void mob_2::Skill()
{
	frame += Delta * 5;
	if (frame >= m_ani.size())
		frame = 0;

	int skill;
}
