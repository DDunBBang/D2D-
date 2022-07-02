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

	void		Set_Dead(void) { m_bDead = true; }


	const INFO&		Get_Info(void)const { return m_tInfo; }

	void		Create_Line();

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

	bool		m_bDead;

	float		m_fSpeed;

	list<CLine*>		m_LineList;
};

