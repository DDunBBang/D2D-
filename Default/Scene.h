#pragma once
class CScene
{
public:
	CScene();
	~CScene();

public:
	virtual		void	Initialize(void) PURE;
	virtual		int		Update(void)	PURE;
	virtual		void	Late_Update(void) PURE;
	virtual		void	Render(HDC hDC) PURE;
	virtual		void	Release(void) PURE;
	
	void Set_Life(int _iLife) { m_iLife = _iLife; }
	void Set_Score(int _iScore) { m_iScore = _iScore; }



protected:
	int m_iLife;
	int m_iScore;
};

