#pragma once
#include "cBullet.h"
class boss_1
{
public:
	vector<cBullet*>& m_bullet;
	cTimer* playerAS = nullptr;
	vector<cTexture*> m_ani = IMAGE->MakeVecImg("boss2");
	Vec2 bpos = CENTER;

	bool b_fire = true;

	float m_Hp;
	float frame = 0;
	float bultime = 0;
	float skilltime = 0;
	float b_count = 4;
	float b_time = 0;

	boss_1(vector<cBullet*>& bullet);
	~boss_1();

	void Update(Vec2 m_pos);
	void Skill(Vec2 m_pos);
	void Render();
	void UIRender();
};

