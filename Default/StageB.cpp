#include "stdafx.h"
#include "StageB.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"
#include "Grow.h"

CStageB::CStageB()
{
}


CStageB::~CStageB()
{
}

void CStageB::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();
	CLineMgr::Get_Instance()->Load_File_B();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(135,495));
	CObj* pObj_ = CAbstractFactory<CLotMonster>::Create(220,150);
	dynamic_cast<CLotMonster*>(pObj_)->Set_Count(2);

	//CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(135, 495));
	CObj* pObj_10 = CAbstractFactory<CLotMonster>::Create(300, 480);
	dynamic_cast<CLotMonster*>(pObj_10)->Set_Count(2);

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CObstacle>::Create(500.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CGrow>::Create(300.f, 300.f));

	CObj* pObj_2 = CAbstractFactory<CObstacle>::Create(350,160);

	dynamic_cast<CObstacle*>(pObj_2)->Set_State(CObstacle::HORIZONTAL);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_2);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_10);


	CObj* pObj_3 = CAbstractFactory<CObstacle>::Create(350, 210);

	dynamic_cast<CObstacle*>(pObj_3)->Set_State(CObstacle::HORIZONTAL);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_3);

	CObj* pObj_4 = CAbstractFactory<CObstacle>::Create(350, 210);

	dynamic_cast<CObstacle*>(pObj_4)->Set_State(CObstacle::VERTICAL);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_4);

	CObj* pObj_5 = CAbstractFactory<CObstacle>::Create(560, 210);

	dynamic_cast<CObstacle*>(pObj_5)->Set_State(CObstacle::VERTICAL);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_5);


	CObj* pObj_6= CAbstractFactory<CObstacle>::Create(350, 400);

	dynamic_cast<CObstacle*>(pObj_6)->Set_State(CObstacle::RECT);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_6);

	//CObj* pObj_7 = CAbstractFactory<CObstacle>::Create(200, 400);

	//dynamic_cast<CObstacle*>(pObj_7)->Set_State(CObstacle::RECT);
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_7);




}

int CStageB::Update(void)
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CStageB::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageB::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	Rectangle(hDC, 50, 50, WINCX-50, WINCY-50);

	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageB::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
