#pragma once
#include "singleton.h"
class cRenderManager :
	public singleton<cRenderManager>
{
	struct VertexType
	{
		Vec3 m_pos;
		Vec2 m_uv;
		inline static constexpr DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
	};

public:
	cRenderManager();
	~cRenderManager();

	LPDIRECT3DVERTEXBUFFER9 m_vb;
	LPDIRECT3DINDEXBUFFER9 m_ib;

	Vec3 camPos, camLook, camUp, projPos;
	D3DXMATRIXA16 matView, matProj;

	void CenterRender(cTexture* ptr, Vec2 pos, float size = 1, float rot = 0);
};

#define RENDER cRenderManager::GetInstance()