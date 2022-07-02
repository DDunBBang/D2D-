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

private:
	void		Key_Input(void);

private:
	D3DXVECTOR3		m_vPosin;
	D3DXVECTOR3		m_vPoint[4];
	D3DXVECTOR3		m_vOriginPoint[4];
	D3DXVECTOR3		m_vFront;

	float			m_fAngle;

};

// 1. ���콺 �����͸� ����ٴϴ� �÷��̾ ������(��, ���� ������ �ƴ� ������ �̿��ؼ� ������)

// 2. ���� ���� �ؿ���








// ������ ������ �ʼ� ���� : �ݵ�� �� ���⺤�Ϳ��� ����

// ����, ������ ������ �̿��Ͽ� ��Į�� ���ϰ� �� ��Į��� ������ �������� �� ���� ���ʹ� ���� ���Ϳ��� �Ѵ�.

//������ ���� : U(x, y, z) V(X`, Y`, Z`)	-> x * X` + y * Y` + z * Z`