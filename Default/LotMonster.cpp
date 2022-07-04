#include "stdafx.h"
#include "LotMonster.h"


CLotMonster::CLotMonster() : m_fAngleSpeed(0.f)
{
}


CLotMonster::~CLotMonster()
{
	Release();
}

void CLotMonster::Initialize(void)
{
	//m_tInfo.vPos = { 400.f, 400.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_fDistance = 30.f;
	m_iCount = 10;

	m_vPoint[0] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y + 10.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y + 10.f, 0.f };

	for (int i = 0; i < m_iCount * 4; ++i) 
	{
		m_vPointTop[i] = { m_vPoint[i % 4].x, m_vPoint[i % 4].y, 0.f };
	}
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointRight[i] = { m_vPoint[i % 4].x, m_vPoint[i % 4].y, 0.f };
	}
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointBottom[i] = { m_vPoint[i % 4].x, m_vPoint[i % 4].y, 0.f };
	}
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointLeft[i] = { m_vPoint[i % 4].x, m_vPoint[i % 4].y, 0.f };
	}

	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	for (int i = 0; i < m_iCount * 4; ++i)
		m_vOriginPointTop[i] = m_vPointTop[i];
	for (int i = 0; i <  m_iCount * 4; ++i)
		m_vOriginPointRight[i] = m_vPointRight[i];
	for (int i = 0; i <  m_iCount * 4; ++i)
		m_vOriginPointBottom[i] = m_vPointBottom[i];
	for (int i = 0; i <  m_iCount * 4; ++i)
		m_vOriginPointLeft[i] = m_vPointLeft[i];

	m_fAngleSpeed = 2.f;
}

int CLotMonster::Update(void)
{
	if (m_bStart)
	{
		m_vMinusPos = m_tInfo.vPos;
		m_bStart = false;
	}

	D3DXMATRIX  matScale, matRotz, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotz, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotz * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];
		m_vPoint[i] -= m_vMinusPos;

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	Create_Rect();

	return 0;
}

void CLotMonster::Late_Update(void)
{
	m_fAngle += D3DXToRadian(m_fAngleSpeed);
}

void CLotMonster::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);
	}
	LineTo(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y);

	//위 
	for (int j = 0; j < m_iCount * 4; j += 4)
	{
		MoveToEx(hDC, (int)m_vPointTop[j].x, (int)m_vPointTop[j].y, nullptr);
		for (int i = j; i < j + 4; ++i)
		{
			LineTo(hDC, (int)m_vPointTop[i].x, (int)m_vPointTop[i].y);
		}
		LineTo(hDC, (int)m_vPointTop[j].x, (int)m_vPointTop[j].y);
	}
	
	//오른쪽 
	for (int j = 0; j < m_iCount * 4; j += 4)
	{
		MoveToEx(hDC, (int)m_vPointRight[j].x, (int)m_vPointRight[j].y, nullptr);
		for (int i = j; i < j + 4; ++i)
		{
			LineTo(hDC, (int)m_vPointRight[i].x, (int)m_vPointRight[i].y);
		}
		LineTo(hDC, (int)m_vPointRight[j].x, (int)m_vPointRight[j].y);
	}

	// 아래
	for (int j = 0; j < m_iCount * 4; j += 4)
	{
		MoveToEx(hDC, (int)m_vPointBottom[j].x, (int)m_vPointBottom[j].y, nullptr);
		for (int i = j; i < j + 4; ++i)
		{
			LineTo(hDC, (int)m_vPointBottom[i].x, (int)m_vPointBottom[i].y);
		}
		LineTo(hDC, (int)m_vPointBottom[j].x, (int)m_vPointBottom[j].y);
	}


	// 왼쪽
	for (int j = 0; j < m_iCount * 4; j += 4)
	{
		MoveToEx(hDC, (int)m_vPointLeft[j].x, (int)m_vPointLeft[j].y, nullptr);
		for (int i = j; i < j + 4; ++i)
		{
			LineTo(hDC, (int)m_vPointLeft[i].x, (int)m_vPointLeft[i].y);
		}
		LineTo(hDC, (int)m_vPointLeft[j].x, (int)m_vPointLeft[j].y);
	}


}

void CLotMonster::Release(void)
{
}

void CLotMonster::Create_Rect()
{
	int iDistance = m_fDistance;
	//위
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointTop[i] = m_vOriginPointTop[i];

		m_vPointTop[i] -= {m_tInfo.vPos.x, m_tInfo.vPos.y + iDistance, 0.f };

		if ((i + 1) % 4 == 0)
		{
			iDistance += m_fDistance;
		}

		if (i == m_iCount * 4 - 1)
		{
			iDistance = m_fDistance;
		}
		D3DXVec3TransformCoord(&m_vPointTop[i], &m_vPointTop[i], &m_tInfo.matWorld);
	}

	//오른쪽
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointRight[i] = m_vOriginPointRight[i];

		m_vPointRight[i] -= {m_tInfo.vPos.x - iDistance, m_tInfo.vPos.y, 0.f };

		if ((i + 1) % 4 == 0)
		{
			iDistance += m_fDistance;
		}

		if (i == m_iCount * 4 - 1)
		{
			iDistance = m_fDistance;
		}
		D3DXVec3TransformCoord(&m_vPointRight[i], &m_vPointRight[i], &m_tInfo.matWorld);
	}

	// 아래
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointBottom[i] = m_vOriginPointBottom[i];

		m_vPointBottom[i] -= {m_tInfo.vPos.x, m_tInfo.vPos.y - iDistance, 0.f };

		if ((i + 1) % 4 == 0)
		{
			iDistance += m_fDistance;
		}

		if (i == m_iCount * 4 - 1)
		{
			iDistance = m_fDistance;
		}
		D3DXVec3TransformCoord(&m_vPointBottom[i], &m_vPointBottom[i], &m_tInfo.matWorld);
	}

	//왼쪽
	for (int i = 0; i < m_iCount * 4; ++i)
	{
		m_vPointLeft[i] = m_vOriginPointLeft[i];

		m_vPointLeft[i] -= {m_tInfo.vPos.x + iDistance, m_tInfo.vPos.y, 0.f };

		if ((i + 1) % 4 == 0)
		{
			iDistance += m_fDistance;
		}

		if (i == m_iCount * 4 - 1)
		{
			iDistance = m_fDistance;
		}
		D3DXVec3TransformCoord(&m_vPointLeft[i], &m_vPointLeft[i], &m_tInfo.matWorld);
	}
}

