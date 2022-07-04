#include "stdafx.h"
#include "StageS.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "Grow.h"
#include "LotMonster.h"


CStageS::CStageS()
{
}


CStageS::~CStageS()
{
}

void CStageS::Initialize(void)
{
	CLineMgr::Get_Instance()->Load_File();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	Create_Obstacle();
	Create_Rot();
	Create_Grow();

	CLineMgr::Get_Instance()->Initialize();
}

int CStageS::Update(void)
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CStageS::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageS::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageS::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}

void CStageS::Create_Obstacle()
{
	CObj*	pObstacle = CAbstractFactory<CObstacle>::Create(10.f,150.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle);

	CObj*	pObstacle2 = CAbstractFactory<CObstacle>::Create(10.f, 225.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_AngleSpeedSet(15.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle2);

	CObj*	pObstacle3 = CAbstractFactory<CObstacle>::Create(10.f,300.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle3);

	CObj*	pObstacle4 = CAbstractFactory<CObstacle>::Create(10.f, 375.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_SpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_AngleSpeedSet(18.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle4);

	CObj*	pObstacle5 = CAbstractFactory<CObstacle>::Create(40.f, 470.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle5);

	CObj*	pObstacle6 = CAbstractFactory<CObstacle>::Create(40.f, 470.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_AngleSpeedSet(10.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle6);

	CObj*	pObstacle7 = CAbstractFactory<CObstacle>::Create(252.f, 15.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle7);

	CObj*	pObstacle8 = CAbstractFactory<CObstacle>::Create(200.f, 70.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle8);

	CObj*	pObstacle9 = CAbstractFactory<CObstacle>::Create(400.f, 498.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle9);

	CObj*	pObstacle10 = CAbstractFactory<CObstacle>::Create(400.f, 498.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle10);
}

void CStageS::Create_Rot()
{
	CObj*	pRot = CAbstractFactory<CLotMonster>::Create(250.f, 200.f);
	dynamic_cast<CLotMonster*>(pRot)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot);

	CObj*	pRot2 = CAbstractFactory<CLotMonster>::Create(515.f, 200.f);
	dynamic_cast<CLotMonster*>(pRot2)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot2);

	CObj*	pRot3 = CAbstractFactory<CLotMonster>::Create(250.f, 400.f);
	dynamic_cast<CLotMonster*>(pRot3)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot3);

	CObj*	pRot4 = CAbstractFactory<CLotMonster>::Create(515.f, 400.f);
	dynamic_cast<CLotMonster*>(pRot4)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot4);
}

void CStageS::Create_Grow()
{
	CObj*	pGrow = CAbstractFactory<CGrow>::Create(400.f,300.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow);
}
