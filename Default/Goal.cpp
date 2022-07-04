#include "stdafx.h"
#include "Goal.h"


CGoal::CGoal()
{
}


CGoal::~CGoal()
{
}

void CGoal::Initialize(void)
{
	m_tRect.left = m_tInfo.vPos.x - 25.f;
	m_tRect.right = m_tInfo.vPos.x + 25.f;
	m_tRect.top = m_tInfo.vPos.y - 25.f;
	m_tRect.bottom = m_tInfo.vPos.y + 25.f;
}

int CGoal::Update(void)
{
	return 0;
}

void CGoal::Late_Update(void)
{
}

void CGoal::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGoal::Release(void)
{
}
