#include "stdafx.h"
#include "StageJ.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"
#include "Grow.h"

CStageJ::CStageJ()
{
}


CStageJ::~CStageJ()
{
}

void CStageJ::Initialize(void)
{	
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(100.f, 100.f));
	
	Creat_Obstacle();
	Creat_Grow();
	Creat_RotMon();

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

void CStageJ::Creat_Obstacle(void)
{
	CObj* pObj1 = CAbstractFactory<CObstacle>::Create(100.f, 100.f);
	dynamic_cast<CObstacle*>(pObj1)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj1)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj1)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj1);

	CObj* pObj2 = CAbstractFactory<CObstacle>::Create(100.f, 200.f);
	dynamic_cast<CObstacle*>(pObj2)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj2)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj2)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj2);

	CObj* pObj3 = CAbstractFactory<CObstacle>::Create(100.f, 300.f);
	dynamic_cast<CObstacle*>(pObj3)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj3)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj3)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj3);

}

void CStageJ::Creat_Grow(void)
{
	CObj* pObj1 = CAbstractFactory<CGrow>::Create(125.f, 125.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj1);
}

void CStageJ::Creat_RotMon(void)
{
}
