#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// ¿ßƒ° ∫§≈Õ
	D3DXVECTOR3		vDir;		// πÊ«‚ ∫§≈Õ

	D3DXVECTOR3		vLook;		// πÊ«‚ ∫§≈Õ
	D3DXVECTOR3		vNormal;	// π˝º± ∫§≈Õ
	
}INFO;


static D3DXVECTOR3			Get_Mouse(void)
{
	POINT		pt;

	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return D3DXVECTOR3(float(pt.x), float(pt.y), 0.f);
}

typedef struct tagPoint
{
	float		fX;
	float		fY;

	tagPoint(void) { ZeroMemory(this, sizeof(tagPoint)); }
	tagPoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

}LINEPOINT;

typedef struct tagLine
{
	LINEPOINT		tLPoint;
	LINEPOINT		tRPoint;

	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(LINEPOINT& tLeft, LINEPOINT& tRight) : tLPoint(tLeft), tRPoint(tRight) {}

}LINE;
