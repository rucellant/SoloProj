#pragma once

//½Ì±Û Åæ
class CKeyMgr
{
private:
	static CKeyMgr* m_pInstance;

	DWORD dwKey;
	DWORD dwKeyDown;
	DWORD dwKeyUp;

private:
	CKeyMgr();
	~CKeyMgr();

public:
	static CKeyMgr* GetInstance();

	void DestroyInstance();

public:
	bool KeyPressing(DWORD dwKey);
	bool KeyDown(DWORD dwKey);
	bool KeyUp(DWORD dwKey);
};

