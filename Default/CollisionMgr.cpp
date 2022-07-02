#include "stdafx.h"
#include "CollisionMgr.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Collision_Line(list<CObj*>* _Dest, list<CLine*>* _Sour)
{
	if (_Sour->empty())
		return false;
	for (auto& Dest : *_Dest)
	{
		for (auto& iter = _Sour->begin(); iter != _Sour->end(); ++iter)
		{
			/*D3DXVECTOR3 vLP = { Dest->Get_Info().vPos.x - (*iter)->Get_Line().tLPoint.fX, Dest->Get_Info().vPos.y - (*iter)->Get_Line().tLPoint.fY, 0.f };
			D3DXVECTOR3 vLR = { (*iter)->Get_Line().tRPoint.fX - (*iter)->Get_Line().tLPoint.fX, (*iter)->Get_Line().tRPoint.fY - (*iter)->Get_Line().tLPoint.fY, 0.f };*/

			D3DXVECTOR3 vLeft = { (*iter)->Get_Line().tLPoint.fX, (*iter)->Get_Line().tLPoint.fY, 0.f };
			D3DXVECTOR3 vRight = { (*iter)->Get_Line().tRPoint.fX, (*iter)->Get_Line().tRPoint.fY, 0.f };

			D3DXVECTOR3 vLR = vRight - vLeft;
			D3DXVECTOR3 vLP = Dest->Get_Info().vPos - vLeft;

			float fDiagnol = D3DXVec3Length(&vLP);
			float fWidth = D3DXVec3Dot(&vLP, &vLR) / D3DXVec3Length(&vLR);

			float fRadian = acosf(fWidth / fDiagnol);

			float fHeight = sinf(fRadian)*fDiagnol;

			if (fHeight < Dest->Get_Radious())
				return true;
		}
	}

	return false;
}

void CCollisionMgr::Collision_Sphere(list<CObj*> _Dest, list<CObj*> _Sour)
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			if (Check_Sphere(Dest, Sour))
			{
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj * pDest, CObj * pSour)
{
	// abs : 절대값을 만들어주는 함수
	float	fWidth = fabs(pDest->Get_Info().vPos.x - pSour->Get_Info().vPos.x);
	float	fHeight = fabs(pDest->Get_Info().vPos.y - pSour->Get_Info().vPos.y);

	// sqrt : 루트를 씌워주는 함수
	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	//float	fRadius = (pDest->Get_Info().fCX + pSour->Get_Info().fCX) * 0.5f;

	return 0;// fRadius >= fDiagonal;	// 충돌을 한 경우
}