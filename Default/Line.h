#pragma once

#include "Include.h"

class CLine
{
public:
	CLine();
	CLine(const LINE& tInfo);
	CLine(LINEPOINT& tLeft, LINEPOINT& tRight);
	~CLine();

public:
	void			Set_Line(LINEPOINT _LP, LINEPOINT _RP) { m_tInfo.tLPoint = _LP; m_tInfo.tRPoint = _RP; }
	const LINE&		Get_Line(void) const { return m_tInfo; }

public:
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

private:
	LINE		m_tInfo;
};

