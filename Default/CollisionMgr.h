#pragma once
#include "Obj.h"

class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static bool	Collision_Line(list<CObj*>* _Dest, list<CLine*>* _Sour);
	static void	Collision_Sphere(list<CObj*> _Dest, list<CObj*> _Sour);
	static bool Check_Sphere(CObj* pDest, CObj* pSour);
	static bool	Collision_Menu(CObj* _Dest, RECT* _Sour);

};