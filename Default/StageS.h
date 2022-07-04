#pragma once
#include "Scene.h"
class CStageS :
	public CScene
{
public:
	CStageS();
	virtual ~CStageS();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

public:
	void	Create_Obstacle();
	void	Create_Rot();
	void	Create_Grow();

	void	Load_File();
};

