#pragma once
#include "cBullet.h"

class TileMap
{
public:
	int hp = 5;							// ��ü ����
	int max_hp = 5;						//
	int speed = 2;						//
	Vec2 pos = Vec2(CENTER.x, float(B)); //
	Vec2 stop_pos;
public:
	static int cell[CELLSIZEX][CELLSIZEY];

	Vec2 first;
	Vec2 second;
	bool line;
	bool IsDrawing;
	bool nodamage = false;
	bool damage = false;

	float timer = 300;
	int coloring_cells = 0;
	int temp = 0;
	int cellxy = CELLSIZEX * CELLSIZEY;
	float frame;
	float bultime = 0;
	float skilltime = 0;
	float b_count = 4;
	float b_time = 0;

	int nowstage;

	POINT cc;

	cTimer* normal = nullptr;

	vector<cTexture*> m_ani;
	vector<cBullet*>& m_bullet;
	vector<cTexture*> ani_bullet = IMAGE->MakeVecImg("bullet");
	cTexture* stage_f;
	cTexture* stage_c;

	static D3DXCOLOR SaveImage[CELLSIZEX][CELLSIZEY];
	static D3DXCOLOR Savebg[CELLSIZEX][CELLSIZEY];

	float coloring_per = 0;

	enum class KeyState
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
	KeyState KEY;

	TileMap(vector<cBullet*>& m_bullet);
	~TileMap();

	void Init(int stage);
	void Update();
	void Render();
	void UIRender();

	void Move();
	void Skill();
	void DrawLine();
	void DrawArea(int draw_flag = 0);
	void AutoFill();
	void SetUp();
	void ChangeScene();

	bool FloodFill(Vec2 pos, int target, int change);
	bool Near(KeyState dir, int target);
	int  Current();
};

