#include "stdafx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = nullptr;

CKeyMgr::CKeyMgr()
	:m_dwKey(0), m_dwKeyDown(0), m_dwKeyUp(0)
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
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CKeyMgr::Update()
{
	m_dwKey = 0;

	if (GetAsyncKeyState('W') & 0x8000)
		m_dwKey |= KEY_UP;
	if (GetAsyncKeyState('S') & 0x8000)
		m_dwKey |= KEY_DOWN;
	if (GetAsyncKeyState('A') & 0x8000)
		m_dwKey |= KEY_LEFT;
	if (GetAsyncKeyState('D') & 0x8000)
		m_dwKey |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_dwKey |= KEY_SPACE;
}

bool CKeyMgr::KeyPressing(TCHAR _Input)
{
	DWORD dwKey = TCHARTODWORD(_Input);

	if (m_dwKey & dwKey)
		return true;

	return false;
}

bool CKeyMgr::KeyDown(TCHAR _Input)
{
	DWORD dwKey = TCHARTODWORD(_Input);

	//이전에 누른 적 없고 현재 눌렀을 때 true
	if (!(m_dwKeyDown & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyDown |= dwKey;
		return true;
	}
		

	//이전에 누른 적 있고 현재 누르지 않았을 때 false
	if ((m_dwKeyDown & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyDown ^= dwKey;
		return false;
	}
		

	return false;
}

bool CKeyMgr::KeyUp(TCHAR _Input)
{
	DWORD dwKey = TCHARTODWORD(_Input);

	//이전에 누른 적 있고 현재 누르지 않았을 때 true
	if ((m_dwKeyUp & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyUp |= dwKey;
		return true;
	}
		

	//이전에 누른 적 없고 현재 눌렀을 때 false
	if (!(m_dwKeyUp & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyUp ^= dwKey;
		return false;
	}
		

	return false;
}

DWORD CKeyMgr::TCHARTODWORD(TCHAR _Input)
{
	DWORD dwKey = 0;

	switch (_Input)
	{
	case 'W':
		dwKey = KEY_UP;
		return dwKey;
	case 'S':
		dwKey = KEY_DOWN;
		return dwKey;
	case 'A':
		dwKey = KEY_LEFT;
		return dwKey;
	case 'D':
		dwKey = KEY_RIGHT;
		return dwKey;
	case VK_SPACE:
		dwKey = KEY_SPACE;
		return dwKey;
	default:
		return 0;
	}
}
