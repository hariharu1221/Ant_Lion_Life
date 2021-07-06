
#include "DXUT.h"
#include "cRenderManager.h"

cRenderManager::cRenderManager()
{
	g_device->CreateVertexBuffer(sizeof(VertexType) * 4, D3DUSAGE_WRITEONLY, VertexType::FVF, D3DPOOL_DEFAULT, &m_vb, NULL);
	VertexType* vertices = nullptr;
	m_vb->Lock(0, 0, (void**)&vertices, 0);

	vertices[0].m_pos = Vec3(-0.5, 0.5, 0);
	vertices[1].m_pos = Vec3(0.5, 0.5, 0);
	vertices[2].m_pos = Vec3(-0.5, -0.5, 0);
	vertices[3].m_pos = Vec3(0.5, -0.5, 0);

	vertices[0].m_uv = Vec2(0, 0);
	vertices[1].m_uv = Vec2(1, 0);
	vertices[2].m_uv = Vec2(0, 1);
	vertices[3].m_uv = Vec2(1, 1);
	m_vb->Unlock();

	g_device->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_ib, NULL);
	WORD idx[] = { 1,2,0,1,3,2 };
	void* indices = NULL;
	m_ib->Lock(0, 0, &indices, 0);
	memcpy(indices, idx, sizeof(WORD) * 6);
	m_ib->Unlock();

	g_device->SetStreamSource(0, m_vb, 0, sizeof(VertexType));
	g_device->SetFVF(VertexType::FVF);
	g_device->SetIndices(m_ib);

	g_device->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	
	projPos = Vec3(-WINSIZEX, WINSIZEY, 100);
	D3DXMatrixOrthoLH(&matProj, projPos.x, projPos.y, 0, projPos.z);
	g_device->SetTransform(D3DTS_PROJECTION, &matProj);

	camPos = Vec3(0, 0, 1);
	camLook = Vec3(0, 0, 0);
	camUp = Vec3(0, 1, 0);

	D3DXMatrixLookAtLH(&matView, &camPos, &camLook, &camUp);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

cRenderManager::~cRenderManager()
{
	m_ib->Release();
	m_vb->Release();
}

void cRenderManager::Update()
{
}

void cRenderManager::SetCamPos(Vec3 pos)
{
	camPos = Vec3(pos.x, pos.y, pos.z + 1);
	camLook = pos;

	D3DXMatrixLookAtLH(&matView, &camPos, &camLook, &camUp);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

void cRenderManager::SetCamRot(Vec3 rot)
{
	camPos = Vec3(0, 0, 1);
	camLook = Vec3(0, 0, 0);
	camUp = Vec3(0, 1, 0);

	D3DXMatrixLookAtLH(&matView, &camPos, &camLook, &camUp);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

void cRenderManager::PlusCamPos(Vec3 pos)
{
	camPos = camPos + pos;
	camLook = camLook + pos;

	D3DXMatrixLookAtLH(&matView, &camPos, &camLook, &camUp);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

void cRenderManager::PlusCamRot(Vec3 rot)
{
}

void cRenderManager::Set()
{
	camPos = Vec3(0, 0, 1);
	camLook = Vec3(0, 0, 0);
	camUp = Vec3(0, 1, 0);
}

void cRenderManager::CamTo()
{
}

void cRenderManager::CenterRender(cTexture* ptr, Vec2 pos, float size, float rot)
{
	D3DXMATRIXA16 matScale, matRot, matPos, matWorld;
	D3DXMatrixTranslation(&matPos, pos.x - WINSIZEX / 2, -(pos.y - WINSIZEY / 2), 0);
	D3DXMatrixScaling(&matScale, ptr->info.Width * size, ptr->info.Height * size, 1);
	D3DXMatrixRotationZ(&matRot, rot);
	matWorld = matScale * matRot * matPos;

	g_device->SetTransform(D3DTS_WORLD, &matWorld);
	g_device->SetTexture(0, ptr->ptr);
	g_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}
