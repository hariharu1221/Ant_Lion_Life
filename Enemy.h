#pragma once
#include "cBullet.h"
class Enemy
{
public:
	float m_Hp;

	Enemy(vector<cBullet*>& bullet);
	~Enemy();

	virtual void Update(Vec2 m_pos);
	virtual void Skill(Vec2 m_pos);
	virtual void Render();
	virtual void UIRender();
};
