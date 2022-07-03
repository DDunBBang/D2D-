#include "stdafx.h"
#include "Obstacle.h"


CObstacle::CObstacle() : m_fAngleSpeed(0.f), m_fDistance(0.f) , m_fSpeedSet(0.f), m_fAngleSpeedSet(0.f)
, m_eState(END), m_bStart(true)
{
}


CObstacle::~CObstacle()
{
	Release();
}

void CObstacle::Initialize(void)
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_vOriginPos = m_tInfo.vPos;

	m_fSpeed = 1.f;
	m_fAngle = 0.f;

	m_vPoint[0] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y + 10.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y + 10.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	m_fDistance = 100.f;
	m_fSpeedSet = 1.f;
	m_fAngleSpeedSet = 3.f;
	m_eState = HORIZONTAL;

	Create_Line();
}

int CObstacle::Update(void)
{
	if (m_bStart)
	{
		m_vMinusPos = m_tInfo.vPos;

		m_bStart = false;
	}

	D3DXMATRIX	matRotZ, matTrans;

	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];
		m_vPoint[i] -= m_vMinusPos;

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	switch (m_eState)
	{
	case CObstacle::RECT:
		Rect_Move();
		break;
	case CObstacle::VERTICAL:
		Vertical_Move();
		break;
	case CObstacle::HORIZONTAL:
		Horizontal_Move();
		break;
	}

	Update_Line();

	return 0;
}

void CObstacle::Late_Update(void)
{
}

void CObstacle::Render(HDC hDC)
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

void CObstacle::Release(void)
{
	for (auto& iter : m_vecLine)
		Safe_Delete<CLine*>(iter);

	m_vecLine.clear();
}

void CObstacle::Rect_Move()
{
	m_fAngle += m_fAngleSpeed;

	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	if(m_vOriginPos.x + m_fDistance <= m_tInfo.vPos.x)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 90.f)
	{
		m_fAngleSpeed = 0.f;

		m_fSpeed = m_fSpeedSet;
	}

	if (m_vOriginPos.y + m_fDistance <= m_tInfo.vPos.y)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 180.f)
	{
		m_fAngleSpeed = 0.f;

		m_fSpeed = m_fSpeedSet;
	}

	if (m_vOriginPos.x - m_fDistance >= m_tInfo.vPos.x)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 270.f)
	{
		m_fAngleSpeed = 0.f;
		m_fSpeed = m_fSpeedSet;
	}

	if (m_vOriginPos.y - m_fDistance >= m_tInfo.vPos.y)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 360.f)
	{
		m_fAngleSpeed = 0.f;
		m_fAngle = 0.f;
		m_fSpeed = m_fSpeedSet;
	}
}

void CObstacle::Vertical_Move()
{
	m_tInfo.vLook = { 0.f, 1.f, 0.f };

	m_fAngle += m_fAngleSpeed;

	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	if (m_vOriginPos.y + m_fDistance <= m_tInfo.vPos.y)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 180.f)
	{
		m_fAngleSpeed = 0.f;
		m_fSpeed = m_fSpeedSet;
	}

	if (m_vOriginPos.y - m_fDistance >= m_tInfo.vPos.y)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 360.f)
	{
		m_fAngleSpeed = 0.f;
		m_fAngle = 0.f;
		m_fSpeed = m_fSpeedSet;
	}
}

void CObstacle::Horizontal_Move()
{
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_fAngle += m_fAngleSpeed;

	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	if (m_vOriginPos.x + m_fDistance <= m_tInfo.vPos.x)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 180.f)
	{
		m_fAngleSpeed = 0.f;
		m_fSpeed = m_fSpeedSet;
	}

	if (m_vOriginPos.x - m_fDistance >= m_tInfo.vPos.x)
	{
		m_fSpeed = 0.f;
		m_fAngleSpeed = m_fAngleSpeedSet;

		m_vOriginPos = m_tInfo.vPos;
	}

	if (m_fAngle == 360.f)
	{
		m_fAngleSpeed = 0.f;
		m_fAngle = 0.f;
		m_fSpeed = m_fSpeedSet;
	}
}
