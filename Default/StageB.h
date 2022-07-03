#pragma once
#include "Scene.h"
class CStageB :
	public CScene
{
public:
	CStageB();
	virtual ~CStageB();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);
};

