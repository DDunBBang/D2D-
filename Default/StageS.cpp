#include "stdafx.h"
#include "StageS.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"

CStageS::CStageS()
{
}


CStageS::~CStageS()
{
}

void CStageS::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
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
