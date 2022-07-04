#pragma once
#include "Scene.h"
class CStageL :
	public CScene
{
public:
	CStageL();
	virtual ~CStageL();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

public:
	void Load_File();
public:
	void	Create_Obstacle();
	void	Create_Rot();
	void	Create_Grow();
};

