#include "stdafx.h"
#include "Player.h"

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

	m_fSpeed = 10.f;
	m_fAngle = 3.f;
	// 주석
	m_vPosin.x = m_tInfo.vPos.x;
	m_vPosin.y = m_tInfo.vPos.y - 100.f;
	m_vPosin.z = 0.f;

	m_vPoint[0] = { m_tInfo.vPos.x - 50.f , m_tInfo.vPos.y - 50.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 50.f , m_tInfo.vPos.y - 50.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 50.f , m_tInfo.vPos.y + 50.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 50.f , m_tInfo.vPos.y + 50.f, 0.f };

	m_vFront = { m_tInfo.vPos.x, m_tInfo.vPos.y - 50.f, 0.f };
}

int CPlayer::Update(void)
{
	m_tInfo.vDir = ::Get_Mouse() - m_tInfo.vPos;
	
	/*float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;
	
	float	fLength2 = sqrtf(m_tInfo.vLook.x * m_tInfo.vLook.x + m_tInfo.vLook.y * m_tInfo.vLook.y);

	m_tInfo.vLook.x /= fLength2;
	m_tInfo.vLook.y /= fLength2;
	m_tInfo.vLook.z = 0.f;

	float	fDot = m_tInfo.vDir.x * m_tInfo.vLook.x + m_tInfo.vDir.y * m_tInfo.vLook.y;

	float	fAngle = acosf(fDot);
			
	if (m_tInfo.vPos.y < ::Get_Mouse().y)
		fAngle = 2.f * D3DX_PI - fAngle;

	m_tInfo.vPos.x += cosf(fAngle) * m_fSpeed;
	m_tInfo.vPos.y -= sinf(fAngle) * m_fSpeed;*/


#pragma region DIRECT 함수를 이용한 과제 풀이

	// 벡터의 크기를 구해주는 함수
	// float	fLength = D3DXVec3Length(&m_tInfo.vDir);

	// 벡터의 정규화(단위 벡터)를 수행하는 함수(결과 값을 저장할 벡터, 정규화를 수행할 벡터)
	/*D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);*/

	// 두 방향 벡터의 내적을 수행하는 함수
	//float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	//float	fAngle = acosf(fDot);

	//if (m_tInfo.vPos.y < ::Get_Mouse().y)
	//	fAngle = 2.f * D3DX_PI - fAngle;

	//m_tInfo.vPos.x += cosf(fAngle) * m_fSpeed;
	//m_tInfo.vPos.y -= sinf(fAngle) * m_fSpeed;


#pragma endregion DIRECT 함수를 이용한 과제 풀이


	Key_Input();

	return 0;

}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[3].x, (int)m_vPoint[3].y, nullptr);
	for (auto& i : m_vPoint)
	{
		LineTo(hDC, (int)i.x, (int)i.y);
	}

	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, (int)m_vPosin.x, (int)m_vPosin.y);
}

void CPlayer::Release(void)
{	
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		for (auto& i : m_vPoint)
		{
			D3DXVECTOR3 vDir = i - m_tInfo.vPos;
			float fRadian = D3DXToRadian(m_fAngle);

			i.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
			i.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));

		}
		D3DXVECTOR3 vDir = m_vFront - m_tInfo.vPos;
		float fRadian = D3DXToRadian(m_fAngle);

		m_vFront.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
		m_vFront.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));
	}
 
	if (GetAsyncKeyState(VK_LEFT))
	{
		for (auto& i : m_vPoint)
		{
			D3DXVECTOR3 vDir = i - m_tInfo.vPos;
			float fRadian = D3DXToRadian(-m_fAngle);

			i.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
			i.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));

		}
		D3DXVECTOR3 vDir = m_vFront - m_tInfo.vPos;
		float fRadian = D3DXToRadian(-m_fAngle);

		m_vFront.x = m_tInfo.vPos.x + (vDir.x*cosf(fRadian) - vDir.y*sinf(fRadian));
		m_vFront.y = m_tInfo.vPos.y + (vDir.x*sinf(fRadian) + vDir.y*cosf(fRadian));
	}

	if (GetAsyncKeyState('A'))
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
	if (GetAsyncKeyState(VK_UP))
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
	}
}