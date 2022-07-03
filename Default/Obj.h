#pragma once

#include "Include.h"
#include "Line.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float _fX, float _fY) 
	{
		m_tInfo.vPos.x = _fX;
		m_tInfo.vPos.y = _fY;
	}
	void		Set_PosX(float _fX) { m_tInfo.vPos.x += _fX; }
	void		Set_PosY(float _fY) { m_tInfo.vPos.y += _fY; }

	void		Set_Dead(void) { m_bDead = true; }

	const INFO&		Get_Info(void)const { return m_tInfo; }
	const float		Get_Radious() const { return fabs(m_tInfo.vPos.y - m_vPoint[0].y); }

	const D3DXMATRIX& Get_matWorld() { return m_tInfo.matWorld; }

	void		Create_Line();
	void		Update_Line();

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int		Update(void)		PURE;
	virtual		void	Late_Update(void)	PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;
	
protected:
	INFO		m_tInfo;

	LINEPOINT	m_tLinePoint[DIR_END][DIR_END];

	D3DXVECTOR3		m_vPoint[4];
	D3DXVECTOR3		m_vOriginPoint[4];

	bool			m_bDead;

	float			m_fSpeed;
	float			m_fAngle;

	vector<CLine*>		m_vecLine;
};

