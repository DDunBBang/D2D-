#pragma once
#include "Obj.h"
class CObstacle :
	public CObj
{
public:
	enum eSTATE	{ RECT, VERTICAL, HORIZONTAL, END};
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
	void Rect_Move();
	void Vertical_Move();
	void Horizontal_Move();

	void Set_Distance(float _fDistance)		{ m_fDistance = _fDistance; }
	void Set_SpeedSet(float _fSpeed)		{ m_fSpeedSet = _fSpeed; }
	void Set_AngleSpeedSet(float _fSpeed)	{ m_fAngleSpeedSet = _fSpeed; }
	void Set_State(eSTATE _eState)			{ m_eState = _eState; }

private:
	D3DXVECTOR3		m_vOriginPos;
	
	float			m_fAngleSpeed;

	float			m_fDistance;
	float			m_fSpeedSet;
	float			m_fAngleSpeedSet;

	eSTATE			m_eState;
};

