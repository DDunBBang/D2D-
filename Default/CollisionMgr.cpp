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
			if ((*iter)->Get_Line().tLPoint.fX == (*iter)->Get_Line().tRPoint.fX)
			{
				if (Dest->Get_Info().vPos.y + Dest->Get_Radious() < (*iter)->Get_Line().tLPoint.fY)
					continue;
				else if (Dest->Get_Info().vPos.y - Dest->Get_Radious() > (*iter)->Get_Line().tRPoint.fY)
					continue;
			}
			else if ((*iter)->Get_Line().tLPoint.fY == (*iter)->Get_Line().tRPoint.fY)
			{
				if (Dest->Get_Info().vPos.x + Dest->Get_Radious() < (*iter)->Get_Line().tLPoint.fX)
					continue;
				else if (Dest->Get_Info().vPos.x - Dest->Get_Radious() > (*iter)->Get_Line().tRPoint.fX)
					continue;
			}

			D3DXVECTOR3 vLeft = { (*iter)->Get_Line().tLPoint.fX, (*iter)->Get_Line().tLPoint.fY, 0.f };
			D3DXVECTOR3 vRight = { (*iter)->Get_Line().tRPoint.fX, (*iter)->Get_Line().tRPoint.fY, 0.f };

			D3DXVECTOR3 vLR = vRight - vLeft;
			D3DXVECTOR3 vLP = Dest->Get_Info().vPos - vLeft;

			float fDiagnol = D3DXVec3Length(&vLP);
			float fWidth = D3DXVec3Dot(&vLP, &vLR) / D3DXVec3Length(&vLR);

			float fRadian = acosf(fWidth / fDiagnol);

			float fHeight = sinf(fRadian)*fDiagnol;

			if (fHeight < Dest->Get_Radious())
			{
				float fLength = fabs(fHeight - Dest->Get_Radious());

				if ((*iter)->Get_Line().tLPoint.fX == (*iter)->Get_Line().tRPoint.fX)
				{
					if (Dest->Get_Info().vPos.x < (*iter)->Get_Line().tLPoint.fX)
						Dest->Set_PosX(-(fLength));
					else
						Dest->Set_PosX((fLength));
				}
				else if ((*iter)->Get_Line().tLPoint.fY == (*iter)->Get_Line().tRPoint.fY)
				{
					if (Dest->Get_Info().vPos.y < (*iter)->Get_Line().tLPoint.fY)
						Dest->Set_PosY(-(fLength));
					else
						Dest->Set_PosY((fLength));
				}

				return true;
			}
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
				Dest->Set_Dead();
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

	float	fRadius = (pDest->Get_Radious() + pSour->Get_Radious()) * 0.5f;

	return fRadius >= fDiagonal;	// 충돌을 한 경우
}

bool CCollisionMgr::Collision_Menu(CObj * _Dest, RECT* _Sour)
{
	if (_Dest->Get_Info().vPos.x > _Sour->left &&
		_Dest->Get_Info().vPos.x < _Sour->right &&
		_Dest->Get_Info().vPos.y > _Sour->top &&
		_Dest->Get_Info().vPos.y < _Sour->bottom)
		return true;

	return false;
}
