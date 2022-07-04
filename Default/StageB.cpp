#include "stdafx.h"
#include "StageB.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"
#include "Grow.h"
#include "Goal.h"

CStageB::CStageB()
{
}


CStageB::~CStageB()
{
}

void CStageB::Initialize(void)
{
	Load_File();
	CLineMgr::Get_Instance()->Initialize();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(135,495));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GOAL, CAbstractFactory<CGoal>::Create(430.f, 495.f));
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

void CStageB::Load_File()
{
	// 1. ���� ����
	HANDLE	hFile = CreateFile(L"../Data/LineB.dat",	// ���� ��ο� �̸��� ����ϴ� �Ű�����
		GENERIC_READ,		// ��� ����, GENERIC_WRITE(����), GENERIC_READ(�б�)
		NULL,				// ���� ���, ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ �� ����� �� ���ΰ�, NULL�� ���� �� �������� ����
		NULL,				// ���� �Ӽ�, NULL�� ��� �⺻ ������ ����
		OPEN_EXISTING,		// ���� ���� ���, �ش� ������ ��� �۾��� ������ �ƴϸ� ���� ���� ������ ���� CREATE_ALWAYS(���� ����) : ������ ���ٸ� ����, ������ �����,  OPEN_EXISTING(�б� ����) : ������ ���� ��쿡�� ����
		FILE_ATTRIBUTE_NORMAL, // ���� �Ӽ� ����, FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� �Ϲ����� ���� ����
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����, �츰 �� ���� NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Load File", L"Error", MB_OK);
		return;
	}

	// 2. ���� ����

	DWORD	dwByte = 0;

	LINE		tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		CLineMgr::Get_Instance()->Get_LineList()->push_back(new CLine(tInfo));
	}


	// 3. ������ ���� �Ҹ��ϱ�
	CloseHandle(hFile);
}
