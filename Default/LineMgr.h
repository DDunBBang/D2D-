#pragma once

#include "Line.h"

class CLineMgr
{
private:
	CLineMgr();
	//CLineMgr(const CLineMgr& rhs) = delete;
	~CLineMgr();

public:
	void		Initialize(void);
	int			Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

	bool		Collision_Line(float fX, float* pY);

	void		Save_File(void);
	void		Load_File(void);


public:
	static		CLineMgr*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CLineMgr;

		return m_pInstance;
	}

	static		void			Destroy_Instance(void)
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
private:
	static		CLineMgr*		m_pInstance;
	list<CLine*>				m_LineList;

	LINEPOINT					m_tLinePoint[DIR_END];

};

