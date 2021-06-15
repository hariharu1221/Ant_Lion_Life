#pragma once
#include "cBullet.h"
class cMBullet :
	public cBullet
{
public:
	cMBullet(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 700);
	virtual ~cMBullet();
	float m_speed;
	float timer = 0;
	int count = 0;
	vector<cTexture*> m_ani = IMAGE->MakeVecImg("bullet");

	// cBullet��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};

