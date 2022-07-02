#include "stdafx.h"
#include "StageL.h"
#include "LineMgr.h"
#include "ObjMgr.h"

CStageL::CStageL()
{
}


CStageL::~CStageL()
{
}

void CStageL::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();
}

int CStageL::Update(void)
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CStageL::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageL::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageL::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
