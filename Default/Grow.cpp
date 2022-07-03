#include "stdafx.h"
#include "Grow.h"


CGrow::CGrow()
{
}


CGrow::~CGrow()
{
	Release();
}

void CGrow::Initialize(void)
{
	m_bGrow = true;
	m_fSize = 1.f;

	m_vPoint[0] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y + 10.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y + 10.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	Create_Line();
}

int CGrow::Update(void)
{

	D3DXMATRIX	matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, m_fSize, m_fSize, m_fSize);
	//D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];
		m_vPoint[i] -= {400.f, 300.f, 0.f };

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	Update_Line();
	return 0;
}

void CGrow::Late_Update(void)
{
	if (m_bGrow)
	{
		m_fSize += 0.1f;
		if (m_fSize >= 5)
			m_bGrow = false;
	}
	else
	{
		m_fSize -= 0.1f;
		if (m_fSize <= 0)
			m_bGrow = true;
	}
}

void CGrow::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, m_vPoint[i].x, m_vPoint[i].y);

		if (i > 0)
			continue;
	}
	LineTo(hDC, m_vPoint[0].x, m_vPoint[0].y);
}

void CGrow::Release(void)
{
	for (auto& iter : m_vecLine)
		Safe_Delete<CLine*>(iter);

	m_vecLine.clear();
}
