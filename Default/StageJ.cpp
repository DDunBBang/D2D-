#include "stdafx.h"
#include "StageJ.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"

CStageJ::CStageJ()
{
}


CStageJ::~CStageJ()
{
}

void CStageJ::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
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
