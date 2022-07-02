#include "stdafx.h"
#include "Stage.h"
#include "Include.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Monster.h"

CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

}

int CStage::Update(void)
{
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

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
}
