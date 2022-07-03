#include "stdafx.h"
#include "StageS.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "Grow.h"


CStageS::CStageS()
{
}


CStageS::~CStageS()
{
}

void CStageS::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	Create_Obstacle();

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
	CObj*	Obj = CAbstractFactory<CObstacle>::Create(400.f,200.f);
	dynamic_cast<CObstacle*>(Obj)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(Obj)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(Obj)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(Obj)->Set_Distance(150.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, Obj);

	CObj*	Obj2 = CAbstractFactory<CObstacle>::Create(200.f,300.f);
	dynamic_cast<CObstacle*>(Obj2)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(Obj2)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(Obj2)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(Obj2)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, Obj2);
}
