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
	// 1. ���� ����
	HANDLE	hFile = CreateFile(L"../Data/LineS.dat",	// ���� ��ο� �̸��� ����ϴ� �Ű�����
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


#ifdef _DEBUG
	MessageBox(g_hWnd, L"Load ����", L"����", MB_OK);
#endif // _DEBUG
}
