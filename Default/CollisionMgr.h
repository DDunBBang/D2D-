#pragma once
#include "Obj.h"

class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:

	static void	Collision_Sphere(list<CObj*> _Dest, list<CObj*> _Sour);
	static bool Check_Sphere(CObj* pDest, CObj* pSour);

};

