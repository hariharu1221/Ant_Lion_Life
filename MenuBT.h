#pragma once
class MenuBT
{

private:
	D3DXIMAGE_INFO	   m_Img;
	LPDIRECT3DTEXTURE9 m_Tex[6];

	Vector2 m_cen;
	Vector2 m_pos = Vector2(0, 0);
	Vector2 size = Vector2(0.5, 0.5);
	Vector3 v_pos = Vector3(0, 0, 0);

	D3DXMATRIX		   mat;
public:
	int select = 1;

	MenuBT();
	~MenuBT();

	void Init(IDirect3DDevice9* pdDevice);
	void Update();
	void Render(ID3DXSprite* pdSprite);
	void Release();



};

