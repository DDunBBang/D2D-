#pragma once
#include "Scene.h"
class CStageJ :
	public CScene
{
public:
	CStageJ();
	virtual ~CStageJ();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

	void	Creat_Obstacle(void);
	void	Creat_Grow(void);
	void	Creat_RotMon(void);

public:
	void	Load_File();
};

