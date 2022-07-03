#pragma once
#include "Obj.h"
class CObstacle :
	public CObj
{
public:
	CObstacle();
	virtual ~CObstacle();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void Test_Move();
	void Test_Patrol();

	void Set_Distance(float _fDistance)		{ m_fDistance = _fDistance; }
	void Set_SpeedSet(float _fSpeed)		{ m_fSpeedSet = _fSpeed; }
	void Set_AngleSpeedSet(float _fSpeed)	{ m_fAngleSpeedSet = _fSpeed; }

private:
	D3DXVECTOR3		m_vOriginPos;
	
	float			m_fAngleSpeed;

	float			m_fDistance;
	float			m_fSpeedSet;
	float			m_fAngleSpeedSet;
};

