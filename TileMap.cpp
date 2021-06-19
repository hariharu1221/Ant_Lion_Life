#include "DXUT.h"
#include "TileMap.h"
#include "cMBullet.h"

TileMap::TileMap(vector<cBullet*>& bullet)
	:m_bullet(bullet)
{
}

TileMap::~TileMap()
{
	SAFE_DELETE(normal);
}

int TileMap::cell[CELLSIZEX][CELLSIZEY] = { 0, };

D3DXCOLOR TileMap::SaveImage[CELLSIZEX][CELLSIZEY];
D3DXCOLOR TileMap::Savebg[CELLSIZEX][CELLSIZEY];

void TileMap::Init(int stage)
{
	nowstage = stage;
	switch (stage)
	{
	case 0:
	case 1:
		stage_f = IMAGE->FindImage("stage_f");
		stage_c = IMAGE->FindImage("stage_c");
		break;
	case 2:
		stage_f = IMAGE->FindImage("stage_f");
		stage_c = IMAGE->FindImage("stage_c");
		break;
	}
	SetUp();
	IsDrawing = true;
	DrawArea();
	IsDrawing = false;
}

void TileMap::Update()
{
	ChangeScene();
	Skill();
	Move();
	cc = { int(pos.x - x_gap), int(pos.y - y_gap) };
}

void TileMap::Skill()
{
	frame += 0.5;
	if (frame == m_ani.size())
		frame = 0;

	if (b_time > 0.3) { b_count++; b_time = 0; }
	if (b_count == ani_bullet.size())	{ b_count = 4; damage = false; }

	timer -= Delta;
	b_time += Delta;
}

void TileMap::Move()
{
	if (INPUT->KeyPress(VK_UP) && pos.y >= 0)  //움직
	{ 
		for (size_t i = 0; i < speed; i++)
		{
			KEY = KeyState::UP;
			pos.y--;

			if (Current() == 1) //선일 경우
				pos.y++;

			if (pos.y < T)
				pos.y = T;

			if (Current() == 2)
			{
				DrawArea();
			}
			else
				if (!Near(KEY, 3))
					DrawLine();
		}
	}
	else if (INPUT->KeyPress(VK_DOWN) && pos.y <= (WINSIZEY - 0)) 
	{ 
		for (size_t i = 0; i < speed; i++)
		{
			KEY = KeyState::DOWN;
			pos.y++;

			if (Current() == 1)
				pos.y--;

			if (pos.y > B)
				pos.y = B;

			if (Current() == 2)
				DrawArea();
			else
				if (!Near(KEY, 3))
					DrawLine();
		}
	}
	else if (INPUT->KeyPress(VK_LEFT) && pos.x >= 0) 
	{ 
		for (size_t i = 0; i < speed; i++)
		{
			KEY = KeyState::LEFT;
			pos.x--;

			if (Current() == 1)
				pos.x++;

			if (pos.x < L)
				pos.x = L;

			if (Current() == 2)
				DrawArea();
			else
				if (!Near(KEY, 3))
					DrawLine();
		}
	}
	else if (INPUT->KeyPress(VK_RIGHT) && pos.x <= (WINSIZEX - 0)) 
	{ 
		for (size_t i = 0; i < speed; i++)
		{
			KEY = KeyState::RIGHT;

			pos.x++;

			if (Current() == 1)
				pos.x--;

			if (pos.x > R - 1)
				pos.x = R - 1;

			if (Current() == 2)
				DrawArea();
			else
				if (!Near(KEY, 3))
					DrawLine();
		}
	}
}

void TileMap::DrawLine()
{
	IsDrawing = true;

	D3DLOCKED_RECT lr;
	stage_f->ptr->LockRect(0, &lr, 0, D3DLOCK_DISCARD);

	DWORD* pixel = (DWORD*)lr.pBits;
	POINT c = { pos.x - x_gap,pos.y - y_gap };
	int index = c.y * CELLSIZEX + c.x;
	cell[c.x][c.y] = 1;
	pixel[index] = D3DCOLOR_RGBA(0, 255, 255, 255);

	stage_f->ptr->UnlockRect(0);
}

void TileMap::DrawArea(int draw_flag)
{
	if (!IsDrawing) { first = pos; return; }
	IsDrawing = false;

	DrawArea(1);

	D3DLOCKED_RECT lr;
	stage_f->ptr->LockRect(0, &lr, 0, D3DLOCK_DISCARD);
	DWORD* pixel = (DWORD*)lr.pBits;

	for (int y = CELLSIZEY - 1; y != -1; --y)
	{
		for (int x = CELLSIZEX - 1; x != -1; --x)
		{
			D3DXCOLOR Opacity = pixel[y * CELLSIZEX + x];
			switch (cell[x][y])
			{
			case 0:
				Opacity = D3DCOLOR_RGBA(int(Opacity.r * 255), int(Opacity.g * 255), int(Opacity.b * 255), 255);
				break;
			case 1:
				if (draw_flag == 1)
				{
					cell[x][y] = 3;
					Opacity = Savebg[x][y];
					break;
				}
				if (draw_flag == 3)
				{
					cell[x][y] = 0;
					Opacity = Savebg[x][y];
					break;
				}
				Opacity = D3DCOLOR_RGBA(int(SaveImage[x][y].r * 255), int(SaveImage[x][y].g * 255), int(SaveImage[x][y].b * 255), 0);

				second = { float(x),float(y)  };
				cell[x][y] = 2;
				if (cell[x + 1][y] & cell[x - 1][y] == 3 || cell[x][y + 1] & cell[x][y - 1] == 3)
					cell[x][y] = 3;

				coloring_cells++;
			case 2:
				if ((cell[x + 1][y] == 3 && cell[x - 1][y] == 3)
					|| (cell[x][y + 1] == 3 && cell[x][y - 1] == 3))
					cell[x][y] = 3;
			case 3:
				if (cell[x][y] == 3)
					Opacity = SaveImage[x][y];
			}

			pixel[y * CELLSIZEX + x] = Opacity;
		}
	}

	DrawArea(1);
	stage_f->ptr->UnlockRect(0);

	if (draw_flag == 0)
		AutoFill();
}

void TileMap::AutoFill()
{
	if (second == Vec2(0, 0)) return;
	bool isOk = FloodFill({ second.x + 1, second.y + 1 }, 0, 100);

	if (isOk) FloodFill({ second.x + 1, second.y + 1 }, 100, 3);
	else
	{
		FloodFill({ second.x - 1, second.y + 1 }, 0, 3);
		FloodFill({ second.x + 1, second.y + 1 }, 100, 0);

		isOk = FloodFill({ second.x + 1, second.y - 1 }, 0, 100);

		if (isOk) FloodFill({ second.x + 1, second.y - 1 }, 100, 3);
		else
		{
			FloodFill({ second.x + 1, second.y + 1 }, 0, 3);
			FloodFill({ second.x + 1, second.y - 1 }, 100, 0);
		}
	}
	second = { 0,0 };
}

bool TileMap::FloodFill(Vec2 pos, int target, int change)
{
	if (target == change) return true;
	if (cell[(int)pos.x][(int)pos.y] != target) return true;

	queue<Vec2> v2q;

	bool add = false;
	temp = 0;

	if (change == 3)
		add = true;

	cell[(int)pos.x][(int)pos.y] = change;

	v2q.push(pos);

	if (add)
		temp++;

	while (!v2q.empty())
	{
		Vec2 n = v2q.front();
		v2q.pop();

		//if (n.x == (int)(boss->pos.x - x_gap) &&
		//	n.y == (int)(boss->pos.y - y_gap))
		//	return false;
		if (cell[(int)n.x - 1][(int)n.y] == target)
		{
			cell[(int)n.x - 1][(int)n.y] = change;
			v2q.push({ n.x - 1, n.y });
			if (add)
				temp++;
		}
		if (cell[(int)n.x + 1][(int)n.y] == target)
		{
			cell[(int)n.x + 1][(int)n.y] = change;
			v2q.push({ n.x + 1, n.y });
			if (add)
				temp++;
		}
		if (cell[(int)n.x][(int)n.y - 1] == target)
		{
			cell[(int)n.x][(int)n.y - 1] = change;
			v2q.push({ n.x, n.y - 1 });
			if (add)
				temp++;
		}
		if (cell[(int)n.x][(int)n.y + 1] == target)
		{
			cell[(int)n.x][(int)n.y + 1] = change;
			v2q.push({ n.x, n.y + 1 });
			if (add)
				temp++;
		}
	}

	coloring_cells += temp;

	float temp1 = coloring_cells * 100;
	coloring_per = temp1 / cellxy;

	IsDrawing = true;
	DrawArea(1);

	return true;
}

bool TileMap::Near(KeyState dir, int target)
{
	int cx = pos.x - x_gap;
	int cy = pos.y - y_gap;

	switch (dir)
	{
	case KeyState::UP:
		return cell[cx][cy - 1] == target;
		break;
	case KeyState::DOWN:
		return cell[cx][cy + 1] == target;
		break;
	case KeyState::LEFT:
		return cell[cx - 1][cy] == target;
		break;
	case KeyState::RIGHT:
		return cell[cx + 1][cy] == target;
		break;
	}
}

int TileMap::Current()
{
	return cell[(int)pos.x - x_gap][(int)pos.y - y_gap];
}

void TileMap::Render()
{
}

void TileMap::UIRender()
{
	UI->CenterRender(stage_c, CENTER, 1.2);
	UI->CenterRender(stage_f, CENTER, 1);
	if (damage)	UI->CenRender(ani_bullet[int(b_count)], stop_pos);
	RECT hpb = { 0,0,100 + hp * 80,50 };
	UI->CropRender(IMAGE->FindImage("hp_bg"), Vec2(243, 825.5), hpb);


	char str[256];
	if (coloring_per < 10)  sprintf(str, "%.2f", (double)coloring_per);
	else					sprintf(str, "%.1f", (double)coloring_per);
	UI->PrintText(str, Vec2(200, 100), 100);
}

void TileMap::SetUp()
{
	memset(cell, 0, sizeof(cell));

	for (size_t x = 0; x < CELLSIZEX; x++)
		for (size_t y = 0; y < CELLSIZEY; y++)
		{
			if (x == 0 || x == CELLSIZEX - 1 || y == 0 || y == CELLSIZEY - 1)
				cell[x][y] = 1;                    
			else
				cell[x][y] = 0;
		}

	coloring_per = 0;
	coloring_cells = 0;
	temp = 0;

	hp = 5;
	speed = 4;
	timer = 300;
	second = { 0,0 };
	frame = 0;

	m_ani = IMAGE->MakeVecImg("boss");

	D3DLOCKED_RECT lr, Tr;
	stage_c->ptr->LockRect(0, &lr, 0, D3DLOCK_DISCARD); //clear img 저장
	DWORD* pixel = (DWORD*)lr.pBits;
	for (int y = CELLSIZEY - 1; y != -1; --y)
	{
		for (int x = CELLSIZEX - 1; x != -1; --x)
		{
			SaveImage[x][y] = pixel[y * CELLSIZEX + x];
		}
	}
	stage_c->ptr->UnlockRect(0);

	stage_f->ptr->LockRect(0, &Tr, 0, D3DLOCK_DISCARD); //front img 저장
	pixel = (DWORD*)Tr.pBits;
	for (int y = CELLSIZEY - 1; y != -1; --y)
	{
		for (int x = CELLSIZEX - 1; x != -1; --x)
		{
			Savebg[x][y] = pixel[y * CELLSIZEX + x];
		}
	}
	stage_f->ptr->UnlockRect(0);
}

void TileMap::ChangeScene()
{
	if (hp <= 0 || timer <= 0) //죽으면
	{
		IMAGE->ReloadImage("stage_c");
		IMAGE->ReloadImage("stage_f");
		stage_f = IMAGE->FindImage("stage_f");
		stage_c = IMAGE->FindImage("stage_c");
		SetUp();
		DrawArea();
		SCENE->ChangeScene("TitleScene");
	}

	if (coloring_per >= 80)
	{
		switch (nowstage)
		{
		case 0:
			IMAGE->ReloadImage("stage_c");
			IMAGE->ReloadImage("stage_f");
			SCENE->ChangeScene("Stage_1_1");
			break;
		case 1:
			IMAGE->ReloadImage("stage_c");
			IMAGE->ReloadImage("stage_f");
			SCENE->ChangeScene("TitleScene");
			break;
		}
	}
}

//클리어시 이펙트
//왼쪽위 버그 수정