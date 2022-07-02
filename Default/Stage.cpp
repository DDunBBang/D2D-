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
	CLineMgr::Get_Instance()->Initialize();

	m_tRect[0] = { 110, 150, 210, 250 };
	m_tRect[1] = { 270, 150, 370, 250 };
	m_tRect[2] = { 430, 150, 530, 250 };
	m_tRect[3] = { 590, 150, 690, 250 };
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

	for (int i = 0; i < 4; ++i)
		Rectangle(hDC, m_tRect[i].left, m_tRect[i].top, m_tRect[i].right, m_tRect[i].bottom);
	DrawText(hDC, L"STAGE_L", lstrlen(L"STAGE_L"), &m_tRect[0], DT_CENTER);
	DrawText(hDC, L"STAGE_S", lstrlen(L"STAGE_S"), &m_tRect[1], DT_CENTER);
	DrawText(hDC, L"STAGE_B", lstrlen(L"STAGE_B"), &m_tRect[2], DT_CENTER);
	DrawText(hDC, L"STAGE_J", lstrlen(L"STAGE_J"), &m_tRect[3], DT_CENTER);
	
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	CLineMgr::Get_Instance()->Destroy_Instance();
}
