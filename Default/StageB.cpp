#include "stdafx.h"
#include "StageB.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"

CStageB::CStageB()
{
}


CStageB::~CStageB()
{
}

void CStageB::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(200,500));
	CObj* pObj_ = CAbstractFactory<CLotMonster>::Create(300,300);
	dynamic_cast<CLotMonster*>(pObj_)->Set_Count(2);

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CObstacle>::Create(300.f, 300.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObj_);

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
