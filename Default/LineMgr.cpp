#include "stdafx.h"
#include "LineMgr.h"
#include "KeyMgr.h"
//#include "ScrollMgr.h"

CLineMgr*		CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
	ZeroMemory(m_tLinePoint, sizeof(m_tLinePoint));
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize(void)
{

}

int CLineMgr::Update(void)
{
	POINT		pt{};

	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	//.pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();



	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SHIFT) && CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		if ((!m_tLinePoint[DIR_LEFT].fX) && (!m_tLinePoint[DIR_LEFT].fY))
		{
			m_tLinePoint[DIR_LEFT].fX = (float)pt.x;
			m_tLinePoint[DIR_LEFT].fY = (float)pt.y;
		}
		// ó�� ��ŷ�� ��찡 �ƴ� ��
		else
		{
			if (m_tLinePoint[DIR_LEFT].fX + 10.f > (float)pt.x && m_tLinePoint[DIR_LEFT].fX - 10.f < (float)pt.x) {
				m_tLinePoint[DIR_RIGHT].fX = m_tLinePoint[DIR_RIGHT].fX;
				m_tLinePoint[DIR_RIGHT].fY = (float)pt.y;

				if (m_tLinePoint[DIR_RIGHT].fX < m_tLinePoint[DIR_LEFT].fX)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));
				else if (m_tLinePoint[DIR_RIGHT].fX > m_tLinePoint[DIR_LEFT].fX)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
				else if (m_tLinePoint[DIR_RIGHT].fY > m_tLinePoint[DIR_LEFT].fY)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
				else if (m_tLinePoint[DIR_RIGHT].fY < m_tLinePoint[DIR_LEFT].fY)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));

				m_tLinePoint[DIR_LEFT].fX = m_tLinePoint[DIR_RIGHT].fX;
				m_tLinePoint[DIR_LEFT].fY = m_tLinePoint[DIR_RIGHT].fY;
			}
			else if (m_tLinePoint[DIR_LEFT].fY + 10.f > (float)pt.y && m_tLinePoint[DIR_LEFT].fY - 10.f < (float)pt.y)
			{
				m_tLinePoint[DIR_RIGHT].fX = (float)pt.x;
				m_tLinePoint[DIR_RIGHT].fY = m_tLinePoint[DIR_LEFT].fY;

				if (m_tLinePoint[DIR_RIGHT].fX < m_tLinePoint[DIR_LEFT].fX)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));
				else if (m_tLinePoint[DIR_RIGHT].fX > m_tLinePoint[DIR_LEFT].fX)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
				else if (m_tLinePoint[DIR_RIGHT].fY > m_tLinePoint[DIR_LEFT].fY)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
				else if (m_tLinePoint[DIR_RIGHT].fY < m_tLinePoint[DIR_LEFT].fY)
					m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));

				m_tLinePoint[DIR_LEFT].fX = m_tLinePoint[DIR_RIGHT].fX;
				m_tLinePoint[DIR_LEFT].fY = m_tLinePoint[DIR_RIGHT].fY;
			}
		}
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		// ó�� ���콺 ��ŷ�� �� ���
		if ((!m_tLinePoint[DIR_LEFT].fX) && (!m_tLinePoint[DIR_LEFT].fY))
		{
			m_tLinePoint[DIR_LEFT].fX = (float)pt.x;
			m_tLinePoint[DIR_LEFT].fY = (float)pt.y;
		}
		// ó�� ��ŷ�� ��찡 �ƴ� ��
		else
		{
			m_tLinePoint[DIR_RIGHT].fX = (float)pt.x;
			m_tLinePoint[DIR_RIGHT].fY = (float)pt.y;

			if(m_tLinePoint[DIR_RIGHT].fX < m_tLinePoint[DIR_LEFT].fX)
				m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));
			else if(m_tLinePoint[DIR_RIGHT].fX > m_tLinePoint[DIR_LEFT].fX)
				m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
			else if(m_tLinePoint[DIR_RIGHT].fY > m_tLinePoint[DIR_LEFT].fY)
				m_LineList.push_back(new CLine(m_tLinePoint[DIR_LEFT], m_tLinePoint[DIR_RIGHT]));
			else if(m_tLinePoint[DIR_RIGHT].fY < m_tLinePoint[DIR_LEFT].fY)
				m_LineList.push_back(new CLine(m_tLinePoint[DIR_RIGHT], m_tLinePoint[DIR_LEFT]));

			m_tLinePoint[DIR_LEFT].fX = m_tLinePoint[DIR_RIGHT].fX;
			m_tLinePoint[DIR_LEFT].fY = m_tLinePoint[DIR_RIGHT].fY;
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_CONTROL) && CKeyMgr::Get_Instance()->Key_Down('Z'))
	{
		m_LineList.pop_back();
	}
	else if (CKeyMgr::Get_Instance()->Key_Down('S'))
	{
		Save_File();
		return 0;
	}

	else if (CKeyMgr::Get_Instance()->Key_Down('L'))
	{
		Load_File();
		return 0;
	}

	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	//	//CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	//	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	//		//CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);


	return 0;
}

void CLineMgr::Late_Update(void)
{

}

void CLineMgr::Render(HDC hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(hDC);
}

void CLineMgr::Release(void)
{
	for_each(m_LineList.begin(), m_LineList.end(), CDeleteObj());
	m_LineList.clear();
}

void CLineMgr::Save_File(void)
{
	// 1. ���� ����
	HANDLE	hFile = CreateFile(L"../Data/LineJ.dat",	// ���� ��ο� �̸��� ����ϴ� �Ű�����
		GENERIC_WRITE,		// ��� ����, GENERIC_WRITE(����), GENERIC_READ(�б�)
		NULL,				// ���� ���, ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ �� ����� �� ���ΰ�, NULL�� ���� �� �������� ����
		NULL,				// ���� �Ӽ�, NULL�� ��� �⺻ ������ ����
		CREATE_ALWAYS,		// ���� ���� ���, �ش� ������ ��� �۾��� ������ �ƴϸ� ���� ���� ������ ���� CREATE_ALWAYS(���� ����) : ������ ���ٸ� ����, ������ �����,  OPEN_EXISTING(�б� ����) : ������ ���� ��쿡�� ����
		FILE_ATTRIBUTE_NORMAL, // ���� �Ӽ� ����, FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� �Ϲ����� ���� ����
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����, �츰 �� ���� NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Save File", L"Error", MB_OK);
		return;
	}

	// 2. ���� ����

	DWORD	dwByte = 0;

	for (auto& iter : m_LineList)
	{
		WriteFile(hFile, &(iter->Get_Line()), sizeof(LINE), &dwByte, nullptr);
	}

	// 3. ������ ���� �Ҹ��ϱ�
	CloseHandle(hFile);

#ifdef _DEBUG
	MessageBox(g_hWnd, L"Save ����", L"����", MB_OK);
#endif // _DEBUG

}

void CLineMgr::Load_File(void)
{
	// 1. ���� ����
	HANDLE	hFile = CreateFile(L"../Data/LineJ.dat",	// ���� ��ο� �̸��� ����ϴ� �Ű�����
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

		m_LineList.push_back(new CLine(tInfo));
	}


	// 3. ������ ���� �Ҹ��ϱ�
	CloseHandle(hFile);


#ifdef _DEBUG
	MessageBox(g_hWnd, L"Load ����", L"����", MB_OK);
#endif // _DEBUG

}
