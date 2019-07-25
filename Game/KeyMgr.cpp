#include "stdafx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = nullptr;

CKeyMgr::CKeyMgr()
	:dwKey(0), dwKeyDown(0), dwKeyUp(0)
{
}


CKeyMgr::~CKeyMgr()
{
}

CKeyMgr * CKeyMgr::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance = new CKeyMgr;

	return m_pInstance;
}

void CKeyMgr::DestroyInstance()
{
	if (m_pInstance)
		SAFE_RELEASE(m_pInstance);
}
