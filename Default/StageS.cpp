#include "stdafx.h"
#include "StageS.h"
#include "LineMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Obstacle.h"
#include "Grow.h"
#include "LotMonster.h"


CStageS::CStageS()
{
}


CStageS::~CStageS()
{
}

void CStageS::Initialize(void)
{
	Load_File();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(45.f, 45.f));

	Create_Obstacle();
	Create_Rot();
	Create_Grow();

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

void CStageS::Create_Obstacle()
{
	CObj*	pObstacle = CAbstractFactory<CObstacle>::Create(10.f,150.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(pObstacle)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle);

	CObj*	pObstacle2 = CAbstractFactory<CObstacle>::Create(10.f, 225.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_AngleSpeedSet(15.f);
	dynamic_cast<CObstacle*>(pObstacle2)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle2);

	CObj*	pObstacle3 = CAbstractFactory<CObstacle>::Create(10.f,300.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle3)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle3);

	CObj*	pObstacle4 = CAbstractFactory<CObstacle>::Create(10.f, 375.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_SpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_AngleSpeedSet(18.f);
	dynamic_cast<CObstacle*>(pObstacle4)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle4);

	CObj*	pObstacle5 = CAbstractFactory<CObstacle>::Create(40.f, 470.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(pObstacle5)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle5);

	CObj*	pObstacle6 = CAbstractFactory<CObstacle>::Create(40.f, 470.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_SpeedSet(4.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_AngleSpeedSet(10.f);
	dynamic_cast<CObstacle*>(pObstacle6)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle6);

	CObj*	pObstacle7 = CAbstractFactory<CObstacle>::Create(252.f, 15.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle7)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle7);

	CObj*	pObstacle8 = CAbstractFactory<CObstacle>::Create(200.f, 70.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_SpeedSet(3.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle8)->Set_Distance(100.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle8);

	CObj*	pObstacle9 = CAbstractFactory<CObstacle>::Create(400.f, 498.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_State(CObstacle::HORIZONTAL);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle9)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle9);

	CObj*	pObstacle10 = CAbstractFactory<CObstacle>::Create(400.f, 498.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_State(CObstacle::VERTICAL);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_AngleSpeedSet(6.f);
	dynamic_cast<CObstacle*>(pObstacle10)->Set_Distance(80.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle10);

	CObj*	pObstacle11 = CAbstractFactory<CObstacle>::Create(699.f, 499.f);
	dynamic_cast<CObstacle*>(pObstacle11)->Set_State(CObstacle::RECT);
	dynamic_cast<CObstacle*>(pObstacle11)->Set_SpeedSet(2.f);
	dynamic_cast<CObstacle*>(pObstacle11)->Set_AngleSpeedSet(5.f);
	dynamic_cast<CObstacle*>(pObstacle11)->Set_Distance(50.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pObstacle11);
}

void CStageS::Create_Rot()
{
	CObj*	pRot = CAbstractFactory<CLotMonster>::Create(250.f, 200.f);
	dynamic_cast<CLotMonster*>(pRot)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot);

	CObj*	pRot2 = CAbstractFactory<CLotMonster>::Create(515.f, 200.f);
	dynamic_cast<CLotMonster*>(pRot2)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot2);

	CObj*	pRot3 = CAbstractFactory<CLotMonster>::Create(250.f, 400.f);
	dynamic_cast<CLotMonster*>(pRot3)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot3);

	CObj*	pRot4 = CAbstractFactory<CLotMonster>::Create(515.f, 400.f);
	dynamic_cast<CLotMonster*>(pRot4)->Set_Count(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pRot4);
}

void CStageS::Create_Grow()
{
	CObj*	pGrow = CAbstractFactory<CGrow>::Create(512.f,62.f);
	dynamic_cast<CGrow*>(pGrow)->Set_SizeMax(5);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow);

	CObj*	pGrow2 = CAbstractFactory<CGrow>::Create(726.f, 400.f);
	dynamic_cast<CGrow*>(pGrow2)->Set_SizeMax(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow2);

	CObj*	pGrow3 = CAbstractFactory<CGrow>::Create(726.f, 280.f);
	dynamic_cast<CGrow*>(pGrow3)->Set_SizeMax(3);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow3);

	CObj*	pGrow4 = CAbstractFactory<CGrow>::Create(726.f, 160.f);
	dynamic_cast<CGrow*>(pGrow4)->Set_SizeMax(4);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pGrow4);
}

void CStageS::Load_File()
{
	// 1. 파일 개방
	HANDLE	hFile = CreateFile(L"../Data/LineS.dat",	// 파일 경로와 이름을 명시하는 매개변수
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


#ifdef _DEBUG
	MessageBox(g_hWnd, L"Load 성공", L"성공", MB_OK);
#endif // _DEBUG
}
