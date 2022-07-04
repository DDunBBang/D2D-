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
	CLineMgr::Get_Instance()->Load_File();
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

	CObj* pObj4 = CAbstractFactory<CObstacle>::Create(540.f, 300.f);
	dynamic_cast<CObstacle*>(pObj4)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObj4)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObj4)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj4);

	CObj* pObj5 = CAbstractFactory<CObstacle>::Create(440.f, 300.f);
	dynamic_cast<CObstacle*>(pObj5)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObj5)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObj5)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj5);

	CObj* pObj6 = CAbstractFactory<CObstacle>::Create(440.f, 500.f);
	dynamic_cast<CObstacle*>(pObj6)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObj6)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObj6)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj6);

	CObj* pObj7 = CAbstractFactory<CObstacle>::Create(660.f, 80.f);
	dynamic_cast<CObstacle*>(pObj7)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObj7)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObj7)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj7);

}

void CStageJ::Creat_Grow(void)
{
	CObj*	pGrow = CAbstractFactory<CGrow>::Create(150.f, 537.f);
	dynamic_cast<CGrow*>(pGrow)->Set_SizeMax(6);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow);

	CObj*	pGrow1 = CAbstractFactory<CGrow>::Create(540.f, 300.f);
	dynamic_cast<CGrow*>(pGrow1)->Set_SizeMax(10);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow1);
}

void CStageJ::Creat_RotMon(void)
{
	CObj*	pRot = CAbstractFactory<CLotMonster>::Create(335.f, 420.f);
	dynamic_cast<CLotMonster*>(pRot)->Set_Count(2);
	dynamic_cast<CLotMonster*>(pRot)->Set_AngleSpeed(4.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot);

	CObj*	pRot1 = CAbstractFactory<CLotMonster>::Create(540.f, 150.f);
	dynamic_cast<CLotMonster*>(pRot1)->Set_Count(3);
	dynamic_cast<CLotMonster*>(pRot1)->Set_AngleSpeed(2.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot1);
}
