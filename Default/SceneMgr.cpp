#include "stdafx.h"
#include "SceneMgr.h"
#include "ObjMgr.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_ePreScene(SC_END), m_eCurScene(SC_STAGE)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		CObjMgr::Get_Instance()->Release();
		Safe_Delete(m_pScene);	

		switch (m_eCurScene)
		{
		case SC_STAGE:
			m_pScene = new CStage;
			break;
		case SC_STAGEL:
			m_pScene = new CStageL;
			break;
		case SC_STAGEJ:
			m_pScene = new CStageJ;
			break;
		case SC_STAGEB:
			m_pScene = new CStageB;
			break;
		case SC_STAGES:
			m_pScene = new CStageS;
			break;
		}

		m_pScene->Initialize();

		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Update(void)
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update(void)
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release(void)
{
	Safe_Delete<CScene*>(m_pScene);
}

