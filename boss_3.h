#pragma once
class boss_3
{
public:
	cTimer* playerAS = nullptr;
	vector<cTexture*> m_ani;
	Vec2 bpos = CENTER;

	float m_Hp;
	float frame = 0;
	float b_skill = 0;
	float b_count = 4;
	float b_time = 0;

	bool bulskill = false;
	bool ready = false;

	float xgap = 0;
	float ygap = 0;
	float speed = 80;
	float b_move = 0;
	int dir = 0;
	int sk = 0;

	boss_3();
	~boss_3();

	void Update(Vec2 m_pos, int cell[][CELLSIZEY]);
	void Move();
	void Limit(int cell[][CELLSIZEY]);
	void Skill(Vec2 m_pos);
	void Render();
	void UIRender();
};
