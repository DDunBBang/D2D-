#include "stdafx.h"
#include "StageJ.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "LotMonster.h"
#include "Grow.h"

CStageJ::CStageJ()
{
}


CStageJ::~CStageJ()
{
}

void CStageJ::Initialize(void)
{	
	CLineMgr::Get_Instance()->Load_File();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(100.f, 100.f));
	
	Creat_Obstacle();
	Creat_Grow();
	Creat_RotMon();
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

void CStageJ::Creat_Obstacle(void)
{
	CObj* pObj1 = CAbstractFactory<CObstacle>::Create(100.f, 100.f);
	dynamic_cast<CObstacle*>(pObj1)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj1)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj1)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj1);

	CObj* pObj2 = CAbstractFactory<CObstacle>::Create(100.f, 200.f);
	dynamic_cast<CObstacle*>(pObj2)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj2)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj2)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj2);

	CObj* pObj3 = CAbstractFactory<CObstacle>::Create(100.f, 300.f);
	dynamic_cast<CObstacle*>(pObj3)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObj3)->Set_SpeedSet(4.5f);
	dynamic_cast<CObstacle*>(pObj3)->Set_AngleSpeedSet(5.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj3);

	CObj* pObj4 = CAbstractFactory<CObstacle>::Create(540.f, 300.f);
	dynamic_cast<CObstacle*>(pObj4)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObj4)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObj4)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj4);

	CObj* pObj5 = CAbstractFactory<CObstacle>::Create(440.f, 300.f);
	dynamic_cast<CObstacle*>(pObj5)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObj5)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObj5)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj5);

	CObj* pObj6 = CAbstractFactory<CObstacle>::Create(440.f, 500.f);
	dynamic_cast<CObstacle*>(pObj6)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObj6)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObj6)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj6);

	CObj* pObj7 = CAbstractFactory<CObstacle>::Create(660.f, 80.f);
	dynamic_cast<CObstacle*>(pObj7)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObj7)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObj7)->Set_AngleSpeedSet(90.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, pObj7);

}

void CStageJ::Creat_Grow(void)
{
	CObj*	pGrow = CAbstractFactory<CGrow>::Create(150.f, 537.f);
	dynamic_cast<CGrow*>(pGrow)->Set_SizeMax(6);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow);

	CObj*	pGrow1 = CAbstractFactory<CGrow>::Create(540.f, 300.f);
	dynamic_cast<CGrow*>(pGrow1)->Set_SizeMax(10);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow1);
}

void CStageJ::Creat_RotMon(void)
{
	CObj*	pRot = CAbstractFactory<CLotMonster>::Create(335.f, 420.f);
	dynamic_cast<CLotMonster*>(pRot)->Set_Count(2);
	dynamic_cast<CLotMonster*>(pRot)->Set_AngleSpeed(4.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot);

	CObj*	pRot1 = CAbstractFactory<CLotMonster>::Create(540.f, 150.f);
	dynamic_cast<CLotMonster*>(pRot1)->Set_Count(3);
	dynamic_cast<CLotMonster*>(pRot1)->Set_AngleSpeed(2.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot1);
}

void CStageJ::Load_File()
{
	// 1. 파일 개방
	HANDLE	hFile = CreateFile(L"../Data/LineJ.dat",	// 파일 경로와 이름을 명시하는 매개변수
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
