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

	static CObj*		Create(float _fX, float _fY)
	{
		CObj*		pInstance = new T;
		pInstance->Set_Pos(_fX, _fY);
		pInstance->Initialize();

		return pInstance;
	}

public:
	CAbstractFactory() {	}
	~CAbstractFactory() { }
};


