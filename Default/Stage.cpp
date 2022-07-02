#include "stdafx.h"
#include "Stage.h"
#include "Include.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Monster.h"
#include "LineMgr.h"

CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create());
	CLineMgr::Get_Instance()->Load_File();
	CLineMgr::Get_Instance()->Initialize();

}

int CStage::Update(void)
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
	return 0;
}

void CStage::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
