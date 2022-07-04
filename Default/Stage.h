#pragma once
#include "Scene.h"

class CStage :
	public CScene
{
public:
	CStage();
	virtual ~CStage();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

private:
	RECT	m_tRect[5];
	int m_iScore;
};

