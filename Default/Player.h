#pragma once

#include "Obj.h"

class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void Set_Posin(D3DXVECTOR3 _vPosin) { m_vPosin = _vPosin; }

private:
	void		Key_Input(void);

private:
	D3DXVECTOR3		m_vPosin;
	
	D3DXVECTOR3		m_vFront;

	int m_iLife;
};
