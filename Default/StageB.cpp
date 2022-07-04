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
	// 1. 파일 개방
	HANDLE	hFile = CreateFile(L"../Data/LineB.dat",	// 파일 경로와 이름을 명시하는 매개변수
		GENERIC_READ,		// 모드 지정, GENERIC_WRITE(쓰기), GENERIC_READ(읽기)
		NULL,				// 공유 방식, 파일이 열려 있는 상태에서 다른 프로세스가 오픈할 때 허용을 할 것인가, NULL로 지정 시 공유하지 않음
		NULL,				// 보안 속성, NULL인 경우 기본 값으로 설정
		OPEN_EXISTING,		// 파일 생성 방식, 해당 파일을 열어서 작업할 것인지 아니면 새로 만들 것인지 설정 CREATE_ALWAYS(쓰기 전용) : 파일이 없다면 생성, 있으면 덮어쓰기,  OPEN_EXISTING(읽기 전용) : 파일이 있을 경우에만 연다
		FILE_ATTRIBUTE_NORMAL, // 파일 속성 지정, FILE_ATTRIBUTE_NORMAL : 아무런 속성이 없는 일반적인 파일 생성
		NULL);					// 생성될 파일의 속성을 제공할 템플릿 파일, 우린 안 쓰니 NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Load File", L"Error", MB_OK);
		return;
	}

	// 2. 파일 쓰기

	DWORD	dwByte = 0;

	LINE		tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		CLineMgr::Get_Instance()->Get_LineList()->push_back(new CLine(tInfo));
	}


	// 3. 개방한 파일 소멸하기
	CloseHandle(hFile);
}
