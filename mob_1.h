#pragma once
#include "Enemy.h"
class mob_1 : public Enemy
{
	mob_1();
	~mob_1();

	virtual void Update(Vec2 m_pos);
	virtual void Skill(Vec2 m_pos);
	virtual void Render();
	virtual void UIRender();
};

