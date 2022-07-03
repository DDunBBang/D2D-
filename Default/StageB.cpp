#include "stdafx.h"
#include "StageB.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"

CStageB::CStageB()
{
}


CStageB::~CStageB()
{
}

void CStageB::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
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
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageB::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
