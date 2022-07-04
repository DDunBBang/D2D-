#pragma once
#include "Obj.h"

class CLotMonster :public CObj
{
public: 
	CLotMonster();
	virtual ~CLotMonster();

public:
	virtual void Initialize(void) override;
	virtual int  Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	void	Set_AngleSpeed(float _fSpeed)	{ m_fAngleSpeed = _fSpeed; }
	void	Set_Count(int _iCount)		{ m_iCount = _iCount; }
	void	Set_Pos(D3DXVECTOR3 _Pos)	{ m_tInfo.vPos = _Pos; }

	void	Create_Rect();

private:
	LINEPOINT	m_tLinePoint[DIR_END][DIR_END];

	D3DXVECTOR3		m_vPoint[4];
	D3DXVECTOR3		m_vOriginPoint[4];

	D3DXVECTOR3		m_vPointTop[40];
	D3DXVECTOR3		m_vOriginPointTop[40];

	D3DXVECTOR3		m_vPointRight[40];
	D3DXVECTOR3		m_vOriginPointRight[40];

	D3DXVECTOR3		m_vPointBottom[40];
	D3DXVECTOR3		m_vOriginPointBottom[40];

	D3DXVECTOR3		m_vPointLeft[40];
	D3DXVECTOR3		m_vOriginPointLeft[40];

	D3DXVECTOR3		m_vMinusPos;

	bool		m_bStart;

	int			m_iCount;
	float		m_fAngleSpeed;
};

