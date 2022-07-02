#pragma once
#include "Obj.h"

template<typename T>
class CAbstractFactory
{
public:
	static CObj*		Create(void)
	{
		CObj*		pInstance = new T;
		pInstance->Initialize();

		return pInstance;
	}

	static CObj*		Create(float _fX, float _fY, float _fAngle)
	{
		CObj*		pInstance = new T;
		pInstance->Initialize();
		pInstance->Set_Pos(_fX, _fY);
		pInstance->Set_Angle(_fAngle);

		return pInstance;
	}

	static CObj*		Create(float _fX, float _fY, DIRECTION eDir = DIR_END)
	{
		CObj*		pInstance = new T;
		pInstance->Initialize();
		pInstance->Set_Pos(_fX, _fY);

		if (DIR_END != eDir)
			//pInstance->Set_Dir(eDir);

		return pInstance;
	}

public:
	CAbstractFactory() {	}
	~CAbstractFactory() { }
};


