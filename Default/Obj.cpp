#include "stdafx.h"
#include "Obj.h"

CObj::CObj() : m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
}

CObj::~CObj()
{
}

void CObj::Create_Line()
{
	m_tLinePoint[DIR_UP][DIR_LEFT].fX = m_vPoint[0].x;
	m_tLinePoint[DIR_UP][DIR_LEFT].fY = m_vPoint[0].y;

	m_tLinePoint[DIR_UP][DIR_RIGHT].fX = m_vPoint[1].x;
	m_tLinePoint[DIR_UP][DIR_RIGHT].fY = m_vPoint[1].y;

	m_tLinePoint[DIR_RIGHT][DIR_LEFT].fX = m_vPoint[1].x;
	m_tLinePoint[DIR_RIGHT][DIR_LEFT].fY = m_vPoint[1].y;

	m_tLinePoint[DIR_RIGHT][DIR_RIGHT].fX = m_vPoint[2].x;
	m_tLinePoint[DIR_RIGHT][DIR_RIGHT].fY = m_vPoint[2].y;

	m_tLinePoint[DIR_DOWN][DIR_LEFT].fX = m_vPoint[2].x;
	m_tLinePoint[DIR_DOWN][DIR_LEFT].fY = m_vPoint[2].y;

	m_tLinePoint[DIR_DOWN][DIR_RIGHT].fX = m_vPoint[3].x;
	m_tLinePoint[DIR_DOWN][DIR_RIGHT].fY = m_vPoint[3].y;

	m_tLinePoint[DIR_LEFT][DIR_LEFT].fX = m_vPoint[3].x;
	m_tLinePoint[DIR_LEFT][DIR_LEFT].fY = m_vPoint[3].y;

	m_tLinePoint[DIR_LEFT][DIR_RIGHT].fX = m_vPoint[0].x;
	m_tLinePoint[DIR_LEFT][DIR_RIGHT].fY = m_vPoint[0].y;

	m_LineList.push_back(new CLine(m_tLinePoint[DIR_UP][DIR_LEFT], m_tLinePoint[DIR_UP][DIR_RIGHT]));
	m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT][DIR_LEFT], m_tLinePoint[DIR_RIGHT][DIR_RIGHT]));
	m_LineList.push_back(new CLine(m_tLinePoint[DIR_DOWN][DIR_LEFT], m_tLinePoint[DIR_DOWN][DIR_RIGHT]));
	m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT][DIR_LEFT], m_tLinePoint[DIR_LEFT][DIR_RIGHT]));
}

