#include "stdafx.h"
#include "Stage.h"
#include "Include.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Monster.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Grow.h"
#include "Obstacle.h"
#include "LotMonster.h"

CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize(void)
{
	//CLineMgr::Get_Instance()->Load_File();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CObstacle>::Create(300.f, 300.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CLotMonster>::Create(300.f, 300.f));

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

	for (int i = 0; i < 4; ++i)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (CCollisionMgr::Collision_Menu(CObjMgr::Get_Instance()->Get_Player(), &m_tRect[i]))
			{
				switch (i)
				{
				case 0:
					CSceneMgr::Get_Instance()->Scene_Change(SC_STAGEL);
					break;
				case 1:
					CSceneMgr::Get_Instance()->Scene_Change(SC_STAGES);
					break;
				case 2:
					CSceneMgr::Get_Instance()->Scene_Change(SC_STAGEB);
					break;
				case 3:
					CSceneMgr::Get_Instance()->Scene_Change(SC_STAGEJ);
					break;
				}
			}
		}
	}
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
	CObjMgr::Get_Instance()->Destroy_Instance();
	CLineMgr::Get_Instance()->Destroy_Instance();
}