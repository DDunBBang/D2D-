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

private:
	D3DXVECTOR3		m_vOriginPos;
	
	float			m_fAngleSpeed;
};

