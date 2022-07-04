#include "stdafx.h"
#include "StageJ.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"

CStageJ::CStageJ()
{
}


CStageJ::~CStageJ()
{
}

void CStageJ::Initialize(void)
{	
	CObj* pObj1 = CAbstractFactory<CObstacle>::Create(100.f, 100.f);
	//dynamic_cast<CObstacle*>(pObj1)->Set_State(CObstacle::RECT);
	//dynamic_cast<CObstacle*>(pObj1)->Set_SpeedSet(4.f);
	
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CObstacle>::Create(100.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CObstacle>::Create(100.f, 300.f));

	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CLotMonster>::Create(300.f, 300.f));
	CLineMgr::Get_Instance()->Initialize();
}

int CStageJ::Update(void)
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CStageJ::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageJ::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageJ::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
