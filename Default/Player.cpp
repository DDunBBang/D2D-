#include "stdafx.h"
#include "Player.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_fSpeed = 4.f;
	m_fAngle = 0.f;

	m_vPoint[0] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y - 10.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 10.f , m_tInfo.vPos.y + 10.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 10.f , m_tInfo.vPos.y + 10.f, 0.f };
	
	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];
	m_vFront = { m_tInfo.vPos.x, m_tInfo.vPos.y - 50.f, 0.f };

	Create_Line();
}

int CPlayer::Update(void)
{
	if (m_bStart)
	{
		m_vMinusPos = m_tInfo.vPos;
		m_bStart = false;
	}
	Key_Input();

	D3DXMATRIX	matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	//D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];
		m_vPoint[i] -= m_vMinusPos;

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	Update_Line();
	return 0;
}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC hDC)
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

void CPlayer::Release(void)
{	
	for (auto& iter : m_vecLine)
		Safe_Delete<CLine*>(iter);

	m_vecLine.clear();
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos.x += m_fSpeed;
	}
		
	if (GetAsyncKeyState(VK_LEFT))
	{
		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos.x -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos.y -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);
		m_tInfo.vPos.y += m_fSpeed;
	}
	
	/*if (GetAsyncKeyState('A'))
	{
		D3DXVECTOR3 vDir = m_vPosin - m_tInfo.vPos;

		float fRadian = D3DXToRadian(-m_fAngle);

		m_vPosin.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
		m_vPosin.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));
	}
	if (GetAsyncKeyState('D'))
	{
		D3DXVECTOR3 vDir = m_vPosin - m_tInfo.vPos;

		float fRadian = D3DXToRadian(m_fAngle);

		m_vPosin.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
		m_vPosin.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));
	}

	*/
	/*if (GetAsyncKeyState(VK_UP))
	{
		D3DXVECTOR3 vDir = m_vFront - m_tInfo.vPos;
		D3DXVec3Normalize(&vDir, &vDir);

		m_tInfo.vPos += vDir*m_fSpeed;
		m_vPosin += vDir*m_fSpeed;
		m_vFront += vDir*m_fSpeed;;
		for (auto& i : m_vPoint)
		{
			i += vDir*m_fSpeed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		D3DXVECTOR3 vDir = m_vFront - m_tInfo.vPos;
		D3DXVec3Normalize(&vDir, &vDir);

		m_tInfo.vPos -= vDir*m_fSpeed;
		m_vPosin -= vDir*m_fSpeed;
		m_vFront -= vDir*m_fSpeed;;
		for (auto& i : m_vPoint)
		{
			i -= vDir*m_fSpeed;
		}
	}*/
}