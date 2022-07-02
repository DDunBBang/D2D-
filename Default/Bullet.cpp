#include "stdafx.h"
#include "Bullet.h"
#include "ObjMgr.h"

CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	m_tInfo.vPos = { 100.f, 100.f, 0.f };
	m_fSpeed = 5.f;
}

int CBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vDir = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos; -m_tInfo.vPos;

	float		fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;

	m_tInfo.vPos -= m_tInfo.vDir * m_fSpeed;
	return OBJ_NOEVENT;
}

void CBullet::Late_Update(void)
{
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 5.f),
		int(m_tInfo.vPos.y - 5.f),
		int(m_tInfo.vPos.x + 5.f),
		int(m_tInfo.vPos.y + 5.f));
}

void CBullet::Release(void)
{
}