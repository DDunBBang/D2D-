#pragma once
#include "Monster.h"
class CGrow :
	public CMonster
{
public:
	CGrow();
	virtual ~CGrow();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void Set_SizeMax(int _iSize) { m_fSizeMax = _iSize; }

private:
	bool	m_bGrow;

	int		m_fSizeMax;

	float	m_fSize;
};

