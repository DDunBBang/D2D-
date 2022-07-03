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

	void	Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void	Set_Count(int _iCount) { m_iCount = _iCount; }
	void	Set_Pos(D3DXVECTOR3 _Pos) { m_tInfo.vPos = _Pos; }

private:
	INFO		m_tInfo;

	LINEPOINT	m_tLinePoint[DIR_END][DIR_END];

	D3DXVECTOR3		m_vPoint[4];
	D3DXVECTOR3		m_vOriginPoint[4];

	D3DXVECTOR3		m_vPointTop[20];
	D3DXVECTOR3		m_vOriginPointTop[20];

	D3DXVECTOR3		m_vPointRight[20];
	D3DXVECTOR3		m_vOriginPointRight[20];

	D3DXVECTOR3		m_vPointBottom[20];
	D3DXVECTOR3		m_vOriginPointBottom[20];

	D3DXVECTOR3		m_vPointLeft[20];
	D3DXVECTOR3		m_vOriginPointLeft[20];

	int			m_iCount;

};

